#include "matrix.h"
#include <stdio.h>

int main() {
    Matrix *A = createMatrix(2, 2);
    Matrix *B = createMatrix(2, 2);
    
    if (!A || !B) {
        printf("فشل في إنشاء المصفوفات\n");
        return 1;
    }
    
    A->data[0][0] = 1; A->data[0][1] = 2;
    A->data[1][0] = 3; A->data[1][1] = 4;
    
    B->data[0][0] = 5; B->data[0][1] = 6;
    B->data[1][0] = 7; B->data[1][1] = 8;
    
    printf("Matrix A:\n");
    printMatrix(A);
    
    printf("\nMatrix B:\n");
    printMatrix(B);
    
    Matrix *sum = matrixAdd(A, B);
    if (sum) {
        printf("\nA + B:\n");
        printMatrix(sum);
        freeMatrix(sum);
    } else {
        printf("\nلا يمكن جمع المصفوفات\n");
    }
    
    Matrix *diff = matrixSubtract(A, B);
    if (diff) {
        printf("\nA - B:\n");
        printMatrix(diff);
        freeMatrix(diff);
    } else {
        printf("\nلا يمكن طرح المصفوفات\n");
    }
    
    freeMatrix(A);
    freeMatrix(B);
    
    return 0;
}
