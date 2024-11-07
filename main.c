#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

// Function to create a new matrix
Matrix* createMatrix(int rows, int cols) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (matrix == NULL) {
        return NULL;
    }
    
    matrix->rows = rows;
    matrix->cols = cols;
    
    // Allocate memory for rows
    matrix->data = (int**)malloc(rows * sizeof(int*));
    if (matrix->data == NULL) {
        free(matrix);
        return NULL;
    }
    
    // Allocate memory for columns in each row
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(cols * sizeof(int));
        if (matrix->data[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }
    
    return matrix;
}

// Function to free matrix memory
void freeMatrix(Matrix* matrix) {
    if (matrix == NULL) return;
    
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Function to add two matrices
Matrix* addMatrices(Matrix* matrix1, Matrix* matrix2) {
    // Check if matrices are NULL
    if (matrix1 == NULL || matrix2 == NULL) {
        return NULL;
    }
    
    // Check if matrices have same dimensions
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        return NULL;
    }
    
    // Create result matrix
    Matrix* result = createMatrix(matrix1->rows, matrix1->cols);
    if (result == NULL) {
        return NULL;
    }
    
    // Add corresponding elements
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    
    return result;
}

// Function to add two matrices
Matrix* subtractMatrices(Matrix* matrix1, Matrix* matrix2) {
    // Check if matrices are NULL
    if (matrix1 == NULL || matrix2 == NULL) {
        return NULL;
    }
    
    // Check if matrices have same dimensions
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        return NULL;
    }
    
    // Create result matrix
    Matrix* result = createMatrix(matrix1->rows, matrix1->cols);
    if (result == NULL) {
        return NULL;
    }
    
    // Add corresponding elements
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    
    return result;
}


// Function to scalar multiply matrices
Matrix* scalarMultiplyMatrix(Matrix* matrix1, int n) {
    // Check if matrices are NULL
    if (matrix1 == NULL || n == NULL) {
        return NULL;
    }
    

    
    // Create result matrix
    Matrix* result = createMatrix(matrix1->rows, matrix1->cols);
    if (result == NULL) {
        return NULL;
    }
    
    // Add corresponding elements
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] * n;
        }
    }
    
    return result;
}


// Function to print a matrix
void printMatrix(Matrix* matrix) {
    if (matrix == NULL) {
        printf("NULL matrix\n");
        return;
    }
    
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

