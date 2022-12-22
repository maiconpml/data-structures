#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Node * insert_left_in_row(Node * nodePtr, int newRow, int newCol, int val){

    if(val == 0 && newRow != -1) return nodePtr;

    Node * newElement = (Node *) malloc(sizeof(Node));

    newElement -> left = nodePtr -> left;
    newElement -> right = nodePtr;
    newElement -> left -> right = newElement;
    newElement -> right -> left = newElement;

    newElement -> up = newElement;
    newElement -> down = newElement;

    newElement -> row = newRow;
    newElement -> column = newCol;
    newElement -> value = val;

    return newElement;
}

Node * insert_up_in_column(Node* nodePtr, int newLin, int newCol, int val){
    
    if(val == 0 && newCol != -1) return nodePtr;

    Node * newElement = (Node *) malloc(sizeof(Node));

    newElement -> up = nodePtr -> up;
    newElement -> down = nodePtr;
    newElement -> up -> down = newElement;
    newElement -> down -> up = newElement;

    newElement -> right = newElement;
    newElement -> left = newElement;

    newElement -> row = newLin;
    newElement -> column = newCol;
    newElement -> value = val;

    return newElement;
}

void remove_node(Node* nodePtr){

    nodePtr -> up -> down = nodePtr -> down;
    nodePtr -> down -> up = nodePtr -> up;
    nodePtr -> left -> right = nodePtr -> right;
    nodePtr -> right -> left = nodePtr -> left;

    free(nodePtr);
}

void initialize_matrix(Matrix * matrixPtr, int nrow, int ncol){

    matrixPtr -> nRows = nrow;
    matrixPtr -> nCols = ncol;

    matrixPtr -> head = (Node *) malloc(sizeof(Node));

    matrixPtr -> head -> right = matrixPtr -> head;
    matrixPtr -> head -> left = matrixPtr -> head;
    matrixPtr -> head -> up = matrixPtr -> head;
    matrixPtr -> head -> down = matrixPtr -> head;
}

void clear(Matrix* matrixPtr, int nrow, int ncol){

    deallocate_matrix(matrixPtr);

    initialize_matrix(matrixPtr, nrow, ncol);
}

void define_element(Matrix matrix, int nRow, int nCol, int val){
    
    Node* currentRow = matrix.head -> down;
    Node* currentCol = matrix.head -> right;
    Node* currentElem;
    Node* newElement = NULL;

    while(currentRow -> row < nRow && currentRow != matrix.head){
        currentRow = currentRow -> down;
    }

    if(currentRow -> row == nRow && currentRow != matrix.head){

        currentElem = currentRow -> right;

        while(currentElem -> column < nCol && currentElem != currentRow){
            currentElem = currentElem -> right;
        }
        
        if(currentElem -> column == nCol && val == 0){

            remove_node(currentElem);
        
        }else if(currentElem -> column == nCol){

            currentElem -> value = val;

            return;

        }else newElement = insert_left_in_row(currentElem, nRow, nCol, val);

    }else newElement = insert_left_in_row( insert_up_in_column(currentRow, nRow, -1, 0), nRow, nCol, val);

    while(currentCol -> column < nCol && currentCol != matrix.head){
        currentCol = currentCol -> right;
    }

    if(currentCol -> column == nCol && currentCol != matrix.head && newElement != NULL){

        currentElem = currentCol -> down;

        while(currentElem -> row < nRow && currentElem != currentCol){
            currentElem = currentElem -> down;
        }

        newElement -> down = currentElem;
        newElement -> up = currentElem -> up;
        newElement -> down -> up = newElement;
        newElement -> up -> down = newElement;

    }else if(newElement != NULL){

        currentCol = insert_left_in_row(currentCol, -1, nCol, val);

        newElement -> down = currentCol;
        newElement -> up = currentCol -> up;
        newElement -> down -> up = newElement;
        newElement -> up -> down = newElement;

    }else if(val == 0){

        if(currentRow -> up -> right == currentRow -> up) remove_node(currentRow -> up);

        if(currentCol -> left -> down == currentCol -> down) remove_node(currentCol -> left);
    }
}

void insert_end_column(Node* colPtr, Node* element){

    element -> up = colPtr -> up;
    element -> down = colPtr;
    element -> up -> down = element;
    element -> down -> up = element;
}

void ajusts_column(Matrix matrix){

    Node * currentRow = matrix.head -> down;
    Node * currentElem;

    while(currentRow != matrix.head){

        currentElem = currentRow -> right;

        Node * currentCol = matrix.head -> right;
        
        while(currentElem != currentRow){

            while(currentCol -> column < currentElem -> column && currentCol != matrix.head){
                currentCol = currentCol -> right;
            }

            if(currentCol -> column == currentElem -> column && currentCol != matrix.head){

                insert_end_column(currentCol, currentElem);
            
            }else{

                currentCol = insert_left_in_row(currentCol, -1, currentElem -> column, 0);

                insert_end_column(currentCol, currentElem);
            }

            currentCol = currentCol -> right;
            currentElem = currentElem -> right;
        }

        currentRow = currentRow -> down;
    }
}

void copy_positive_row(Node* destineRow, Node * originRow, Node * startPoint){

    Node * currentNode = startPoint;

    while(currentNode != originRow){

        insert_left_in_row(destineRow, originRow -> row, currentNode -> column, currentNode -> value);

        currentNode = currentNode -> right;
    }
}

bool sum(Matrix* resPtr, Matrix a, Matrix b){

    if(a.nRows != b.nRows || a.nCols != b.nCols) return 0;

    clear(resPtr, a.nRows, a.nCols);

    Node* currentRowA = a.head -> down;
    Node* currentRowB = b.head -> down;
    Node* currentRowRes;
    Node* currentElemA, * currentElemB;

    while(currentRowA != a.head && currentRowB != b.head){

        if(currentRowA -> row < currentRowB -> row){

            currentRowRes = insert_up_in_column(resPtr -> head, currentRowA -> row, -1, 0);

            copy_positive_row(currentRowRes, currentRowA, currentRowA -> right);

            currentRowA = currentRowA -> down;

        }else if(currentRowB -> row < currentRowA -> row){

            currentRowRes = insert_up_in_column(resPtr -> head, currentRowB -> row, -1, 0);

            copy_positive_row(currentRowRes, currentRowB, currentRowB -> right);

            currentRowB = currentRowB -> down;
        
        }else{

            currentRowRes = insert_up_in_column(resPtr -> head, currentRowA -> row, -1, 0);

            currentElemA = currentRowA -> right;
            currentElemB = currentRowB -> right;

            while(currentElemA != currentRowA && currentElemB != currentRowB){

                if(currentElemA -> column < currentElemB -> column){
                    
                    insert_left_in_row(currentRowRes, currentElemA -> row, currentElemA -> column, currentElemA -> value);
                
                    currentElemA = currentElemA -> right;
                
                }else if(currentElemB -> column < currentElemA -> column){
                    
                    insert_left_in_row(currentRowRes, currentElemB -> row, currentElemB -> column, currentElemB -> value);

                    currentElemB = currentElemB -> right;
                
                }else{
                    
                    insert_left_in_row(currentRowRes, currentElemA -> row, currentElemA -> column, (currentElemA -> value) + (currentElemB -> value));

                    currentElemA = currentElemA -> right;
                    currentElemB = currentElemB -> right;                
                }
            }

            if(currentElemA != currentRowA) copy_positive_row(currentRowRes, currentRowA, currentElemA);

            else if(currentElemB != currentRowB) copy_positive_row(currentRowRes, currentRowB, currentElemB);

            if(currentRowRes -> right == currentRowRes) remove_node(currentRowRes);

            currentRowA = currentRowA -> down;
            currentRowB = currentRowB -> down;
        }
    }

    while(currentRowA != a.head){

        currentRowRes = insert_up_in_column(resPtr -> head, currentRowA -> row, -1, 0);

        copy_positive_row(currentRowRes, currentRowA, currentRowA -> right);

        currentRowA = currentRowA -> down;
    }

    while(currentRowB != b.head){

        currentRowRes = insert_up_in_column(resPtr -> head, currentRowB -> row, currentRowB -> column, currentRowB -> value);

        copy_positive_row(currentRowRes, currentRowB, currentRowB -> right);

        currentRowB = currentRowB -> down;
    }

    ajusts_column(*resPtr);

    return 1;
}

bool sub(Matrix* resPtr, Matrix a, Matrix b){

    if(a.nRows != b.nRows || a.nCols != b.nCols) return 0;

    clear(resPtr, a.nRows, a.nCols);

    Node* currentRowA = a.head -> down;
    Node* currentRowB = b.head -> down;
    Node* currentRowRes;
    Node* currentElemA, * currentElemB;

    while(currentRowA != a.head && currentRowB != b.head){

        if(currentRowA -> row < currentRowB -> row){

            currentRowRes = insert_up_in_column(resPtr -> head, currentRowA -> row, -1, 0);

            currentElemA = currentRowA -> right;

            while(currentElemA != currentRowA){

                insert_left_in_row(currentRowRes, currentElemA -> row, currentElemA -> column, currentElemA -> value);

                currentElemA = currentElemA -> right;
            }

            currentRowA = currentRowA -> down;

        }else if(currentRowB -> row < currentRowA -> row){

            currentRowRes = insert_up_in_column(resPtr -> head, currentRowB -> row, -1, 0);

            currentElemB = currentRowB -> right;

            while(currentElemB != currentRowB){

                insert_left_in_row(currentRowRes, currentElemB -> row, currentElemB -> column, -(currentElemB -> value));

                currentElemB = currentElemB -> right;
            }

            currentRowB = currentRowB -> down;
        
        }else{

            currentRowRes = insert_up_in_column(resPtr -> head, currentRowA -> row, -1, 0);

            currentElemA = currentRowA -> right;
            currentElemB = currentRowB -> right;

            while(currentElemA != currentRowA && currentElemB != currentRowB){

                if(currentElemA -> column < currentElemB -> column) insert_left_in_row(currentRowRes, currentElemA -> row, currentElemA -> column, currentElemA -> value);

                else if(currentElemB -> column < currentElemA -> column) insert_left_in_row(currentRowRes, currentElemB -> row, currentElemB -> column, -(currentElemB -> value));

                else insert_left_in_row(currentRowRes, currentElemA -> row, currentElemA -> column, (currentElemA -> value) - (currentElemB -> value));

                currentElemA = currentElemA -> right;
                currentElemB = currentElemB -> right;                
            }

            while(currentElemA != currentRowA){

                insert_left_in_row(currentRowRes, currentElemA -> row, currentElemA -> column, currentElemA -> value);

                currentElemA = currentElemA -> right;
            }

            while(currentElemB != currentRowB){

                insert_left_in_row(currentRowRes, currentElemB -> row, currentElemB -> column, -(currentElemB -> value));

                currentElemB = currentElemB -> right;
            }

            if(currentRowRes -> right == currentRowRes) remove_node(currentRowRes);

            currentRowA = currentRowA -> down;
            currentRowB = currentRowB -> down;
        }

    }

    while(currentRowA != a.head){

        currentRowRes = insert_up_in_column(resPtr -> head, currentRowA -> row, -1, 0);

        currentElemA = currentRowA -> right;

        while(currentElemA != currentRowA){

            insert_left_in_row(currentRowRes, currentElemA -> row, currentElemA -> column, currentElemA -> value);

            currentElemA = currentElemA -> right;
        }

        currentRowA = currentRowA -> down;
    }

    while(currentRowB != b.head){

        currentRowRes = insert_up_in_column(resPtr -> head, currentRowB -> row, currentRowB -> column, currentRowB -> value);

        currentElemB = currentRowB -> right;

        while(currentElemB != currentRowB){

            insert_left_in_row(currentRowRes, currentElemB -> row, currentElemB -> column, -(currentElemB -> value));

            currentElemB = currentElemB -> right;
        }

        currentRowB = currentRowB -> down;
    }

    ajusts_column(*resPtr);

    return 1;
 }

bool mult(Matrix *resPtr, Matrix a, Matrix b){

    if(a.nCols != b.nRows) return 0;

    clear(resPtr, a.nRows, b.nCols);

    Node* currentRowA = a.head -> down;
    Node* currentElemA, * currentElemB, * currentColB, * currentRowRes;
    int sum;

    while(currentRowA != a.head){

        currentColB = b.head -> right;

        currentRowRes = insert_up_in_column(resPtr -> head, currentRowA -> row, -1, 0);

        while(currentColB != b.head){

            sum = 0;
            currentElemA = currentRowA -> right;
            currentElemB = currentColB -> down;

            while(currentElemA != currentRowA && currentElemB != currentColB){

                if(currentElemA -> column < currentElemB -> row){
                    
                    currentElemA = currentElemA -> right;
                }
                else if(currentElemB -> row < currentElemA -> column){
                    
                    currentElemB = currentElemB -> down;
                }
                else{

                    sum += (currentElemA -> value) * (currentElemB -> value);

                    currentElemA = currentElemA -> right;
                    currentElemB = currentElemB -> down;                     
                }
            }

            insert_left_in_row(currentRowRes, currentRowA -> row, currentColB -> column, sum);

            currentColB = currentColB -> right;

        }

        currentRowA = currentRowA -> down;
    }

    ajusts_column(*resPtr);

    return 1;
}

void print(Matrix matrix){

    Node * currentRow = matrix.head -> down;

    printf("(nlin=%d,ncol=%d", matrix.nRows, matrix.nCols);

    while(currentRow != matrix.head){

        Node * currentElem = currentRow -> right;

        while(currentElem != currentRow){

            printf(",[%d,%d]=%d", currentElem -> row, currentElem -> column, currentElem -> value);

            currentElem = currentElem -> right;
        }

        currentRow = currentRow -> down;
    }

    printf(")\n");

}

void deallocate_matrix(Matrix* matrixPtr){

    Node* currentNode = matrixPtr -> head;

    do{

        while(currentNode -> right != currentNode){
            remove_node(currentNode -> left);
        }

        currentNode = currentNode -> down;

    }while(currentNode != matrixPtr -> head);

    while(currentNode -> down != currentNode){
        remove_node(currentNode -> up);
    }

    free(matrixPtr -> head);
}