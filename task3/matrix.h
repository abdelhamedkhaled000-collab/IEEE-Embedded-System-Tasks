#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix* createMatrix(int rows, int cols);
void freeMatrix(Matrix *mat);
Matrix* matrixAdd(Matrix *a, Matrix *b);
Matrix* matrixSubtract(Matrix *a, Matrix *b);
void printMatrix(Matrix *mat);

#endif