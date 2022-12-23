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

/* Deallocates memory used by matrix Ptr. After that initialize
 * matrix Ptr as a matrix of zeros with nrow rows and ncol columns*/
void clear_matrix(Matrix* matrixPtr, int nrow, int ncol);

/* Defines that the element of line "row" and column "col" receives "val".
 * The parameter row < nRows and col < nCols */
void define_element(Matrix matrix, int row, int col, int val);

/* Calculates the sum of matrices a and b putting the result in resPtr.
 * Frees memory previously used by resPtr and overwrites resPtr.*/
bool sum(Matrix *resPtr, Matrix a, Matrix b);

/* Calculates the subtraction of the matrices a and b by placing the
 * result in resPtr. Frees memory previously used by resPtr and overwrites resPtr.*/
bool sub(Matrix *resPtr, Matrix a, Matrix b);

/* Calculates the multiplication of matrices a and b by placing the result in resPtr.
   Frees memory previously used by resPtr and overwrites resPtr. */
bool mult(Matrix *resPtr, Matrix a, Matrix b);

/* Print the matrix mat on the format below:
 * (nrow=100,ncol=200,[0,3]=5,[0,8]=10,[2,9]=50,[5,3]=10,[5,15]=20,[99,0]=33)
 * wich has 100 rows and 200 columns and the only non-zero elements are:
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