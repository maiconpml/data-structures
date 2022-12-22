#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef enum{false, true} bool;

typedef struct auxNode {

  int row, column, value;
  struct auxNode * right;  
  struct auxNode * left;
  struct auxNode * down;
  struct auxNode * up;  
} Node;

typedef Node * BiDimList;

typedef struct {
  BiDimList head;
  int nRows;
  int nCols;
} Matrix;

/* Initialize a matrix of zeros with nrow rows and ncol columns. */
void initialize_matrix(Matrix* matrixPtr, int nrow, int ncol);

/* Deallocates the memory used by matrixPtr. After that, initialize
   matriPtr as a matrix of zeros with nrow rows and ncol columns*/
void clear_matrix(Matrix* matrixPtr, int nrow, int ncol);

/* Define that the element on row "row" and column "col" receives "val".
   The parametre row < nRows and col < nCols */
void define_element(Matrix matrix, int row, int col, int val);

/* Callculate the sum of matrix a and b putting the result in resPtr.
   Free the memory previous used by resPtr and sobrewrite resPtr.*/
bool sum(Matrix *resPtr, Matrix a, Matrix b);

/* Callculate the subtraction of matrix a and b putting the result in resPtr.
   Free the memory previously used by resPtr and sobrewrites resPtr.*/
bool sub(Matrix *resPtr, Matrix a, Matrix b);

/* Callculates the multiplication of matrix a and b putting the result in resPtr.
   Free the memory previously used by resPtr and sobrewrite resPtr. */
bool mult(Matrix *resPtr, Matrix a, Matrix b);

/* Print the matrix mat on the format below:
 * (nrow=100,ncol=200,[0,3]=5,[0,8]=10,[2,9]=50,[5,3]=10,[5,15]=20,[99,0]=33)
 * where this matrux has 100 rows and 200 columns and the only
 * non zero elements are:
 * - in row 0, column 3 with value 5
 * - in row 0, column 8 with value 10
 * - in row 2, column 9 with value 50
 * - in row 5, column 3 with value 10
 * - in row 5, column 15 with value 20
 * - in row 99, column 0 with value 33 */
void print(Matrix matrix);

/* Dealoccates all the memory used by matrixPtr */
void deallocate_matrix(Matrix *matrixPtr);

#endif