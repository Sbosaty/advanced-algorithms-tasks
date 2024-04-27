#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <thread>

// Function to multiply a row by all columns
void multiply_matrix_row (int *mat1, int mat2[3][2], int *result, int cols, int rows) {
    for (int c = 0; c < cols; c++) { // iterate over each column of the result matrix
        result[c] = 0; // initialize the element to 0
        for (int k = 0; k < rows; k++) { // perform dot product of row from mat1 and column from mat2
            result[c] += mat1[k] * mat2[k][c];
        }
    }
}

int main() {
    int rows = 2; 
    int cols = 2; 
    int array1[2][3] = {{100, 20, 3}, {40, 33, 56}}; 
    int array2[3][2] = {{56, 13}, {22, 15}, {9, 100}}; 
    std::thread th[rows];
    int result[2][2]; // Declaration of a 2-D array 2*2

    // Create a thread for each row to perform matrix multiplication
    for (int r = 0; r < rows; r++) {
        th[r] = std::thread(multiply_matrix_row, array1[r], array2, result[r], cols, 3);
    }

    // Wait for all threads to finish
    for (int r = 0; r < rows; r++) {
        th[r].join();
    }

    // Print the original matrices and the result
    printf("Matrix A (2x3):\n");
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) printf("%4d ", array1[r][c]);
        printf("\n");
    }
    printf("Matrix B (3x2):\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 2; c++) printf("%4d ", array2[r][c]);
        printf("\n");
    }
    printf("Result of Multiplication (2x2):\n");
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) printf("%4d ", result[r][c]);
        printf("\n");
    }
    return 0;
}
