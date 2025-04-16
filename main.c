// main.c

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(){
    int** A_data = (int**)malloc(2 * sizeof(int*));
    A_data[0] = (int[]){6, 4};
    A_data[1] = (int[]){8, 3};

    int** B_data = (int**)malloc(2 * sizeof(int*));
    B_data[0] = (int[]){1, 2, 3};
    B_data[1] = (int[]){4, 5, 6};

    int** C_data = (int**)malloc(2 * sizeof(int*));
    C_data[0] = (int[]){2, 4, 6};
    C_data[1] = (int[]){1, 3, 5};

    Matrix A = from_array(A_data, 2, 2);
    Matrix B = from_array(B_data, 2, 3);
    Matrix C = from_array(C_data, 2, 3);

    Matrix B_scaled = scalar_matrix(&B, 3);
    Matrix C_transposed = transpose_matrix(&C);
    Matrix B_scaled_C = multiply_matrix(&B_scaled, &C_transposed);
    Matrix D = add_matrix(&A, &B_scaled_C);

    printf("Resulting Matrix D:\n");
    print_matrix(&D);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);
    free_matrix(&B_scaled);
    free_matrix(&C_transposed);
    free_matrix(&B_scaled_C);
    free_matrix(&D);

    free(A_data);
    free(B_data);
    free(C_data);

    return 0;
}