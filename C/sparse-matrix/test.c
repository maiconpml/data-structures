#include "matrix.h"
#include <stdio.h>

int main(){

    Matrix matrix1, matrix2, matrix3;

    initialize_matrix(&matrix1, 2, 2);
    initialize_matrix(&matrix2, 2, 2);
    initialize_matrix(&matrix3, 2, 2);

    define_element(matrix1, 0, 0, 15);
    define_element(matrix1, 0, 1, 23);
    define_element(matrix1, 1, 0, 134);
    define_element(matrix1, 1, 1, 34);

    printf("Matrix A: ");
    print(matrix1);

    define_element(matrix2, 0, 0, 62);
    define_element(matrix2, 0, 1, 49);
    define_element(matrix2, 1, 0, 136);
    define_element(matrix2, 1, 1, 45);
    
    printf("Matrix B: ");
    print(matrix2);

    sum(&matrix3, matrix1, matrix2);

    printf("A + B: ");
    print(matrix3);

    sub(&matrix3, matrix1, matrix2);

    printf("A - B: ");
    print(matrix3);

    mult(&matrix3, matrix1, matrix2);

    printf("A * B: ");
    print(matrix3);

    deallocate_matrix(&matrix1);
    deallocate_matrix(&matrix2);
    deallocate_matrix(&matrix3);

    return 0;
}