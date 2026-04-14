#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix* createMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;
    
    Matrix *mat = (Matrix*)malloc(sizeof(Matrix));
    if (!mat) return NULL;
    
    mat->rows = rows;
    mat->cols = cols;
    
    mat->data = (int**)malloc(rows * sizeof(int*));
    if (!mat->data) {
        free(mat);
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int*)malloc(cols * sizeof(int));
        if (!mat->data[i]) {
            for (int j = 0; j < i; j++) free(mat->data[j]);
            free(mat->data);
            free(mat);
            return NULL;
        }
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = 0;
        }
    }
    return mat;
}

void freeMatrix(Matrix *mat) {
    if (!mat) return;
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

Matrix* matrixAdd(Matrix *a, Matrix *b) {
    if (!a || !b || a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }
    
    Matrix *result = createMatrix(a->rows, a->cols);
    if (!result) return NULL;
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

Matrix* matrixSubtract(Matrix *a, Matrix *b) {
    if (!a || !b || a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }
    
    Matrix *result = createMatrix(a->rows, a->cols);
    if (!result) return NULL;
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return result;
}

void printMatrix(Matrix *mat) {
    if (!mat) {
        printf("Matrix is NULL\n");
        return;
    }
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}