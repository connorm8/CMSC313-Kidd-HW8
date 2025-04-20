// Test.c

#include "matrix.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void test_matrix(){
    int** A_data = (int**)malloc(2 * sizeof(int*));
    A_data[0] = (int[]){1, 2};
    A_data[1] = (int[]){3, 4};

    int** B_data = (int**)malloc(2 * sizeof(int*));
    B_data[0] = (int[]){5, 6};
    B_data[1] = (int[]){7, 8};

    int** sum_data = (int**)malloc(2 * sizeof(int*));
    sum_data[0] = (int[]){6, 8};
    sum_data[1] = (int[]){10, 12};

    int** scalar_data = (int**)malloc(2 * sizeof(int*));
    scalar_data[0] = (int[]){2, 4};
    scalar_data[1] = (int[]){6, 8};

    int** product_data = (int**)malloc(2 * sizeof(int*));
    product_data[0] = (int[]){19, 22};
    product_data[1] = (int[]){43, 50};

    int** transpose_data = (int**)malloc(2 * sizeof(int*));
    transpose_data[0] = (int[]){1, 3};
    transpose_data[1] = (int[]){2, 4};

    Matrix A = from_array(A_data, 2, 2);
    Matrix B = from_array(B_data, 2, 2);
    Matrix expected_sum = from_array(sum_data, 2, 2);
    Matrix expected_scalar = from_array(scalar_data, 2, 2);
    Matrix expected_product = from_array(product_data, 2, 2);
    Matrix expected_transpose = from_array(transpose_data, 2, 2);

    Matrix sum = add_matrix(&A, &B);
    Matrix scalar = scalar_matrix(&A, 2);
    Matrix product = multiply_matrix(&A, &B);
    Matrix transposed = transpose_matrix(&A);

    bool values_correct = false;

    if(sum.rows != expected_sum.rows || sum.cols != expected_sum.cols){
        printf("Testing addition matrix size: False\n");
    }else{
        printf("Testing addition matrix size: True\n");

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(sum.data[i][j] != expected_sum.data[i][j]){
                    values_correct = false;
                }
            }
        }

        values_correct = true;
        printf("Testnig addition values: %s\n", values_correct ? "True" : "False");
    }
    
    values_correct = false;

    if(scalar.rows != expected_scalar.rows || scalar.cols != expected_scalar.cols){
        printf("Testing scalar multiplication matrix size: False\n");
    }else{
        printf("Testing scalar multiplication matrix size: True\n");

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(scalar.data[i][j] != expected_scalar.data[i][j]){
                    values_correct = false;
                }
            }
        }

        values_correct = true;
        printf("Testnig scalar multiplication values: %s\n", values_correct ? "True" : "False");
    }
    
    values_correct = false;

    if(product.rows != expected_product.rows || product.cols != expected_product.cols){
        printf("Testing matrix multiplication matrix size: False\n");
    }else{
        printf("Testing matrix multiplication matrix size: True\n");

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(product.data[i][j] != expected_product.data[i][j]){
                    values_correct = false;
                }
            }
        }

        values_correct = true;
        printf("Testnig matrix multiplication values: %s\n", values_correct ? "True" : "False");
    }

    values_correct = false;

    if(transposed.rows != expected_transpose.rows || transposed.cols != expected_transpose.cols){
        printf("Testing transposed matrix size: False\n");
    }else{
        printf("Testing transposed matrix size: True\n");

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(transposed.data[i][j] != expected_transpose.data[i][j]){
                    values_correct = false;
                }
            }
        }

        values_correct = true;
        printf("Testnig transposed values: %s\n", values_correct ? "True" : "False");
    }

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&expected_sum);
    free_matrix(&expected_scalar);
    free_matrix(&expected_product);
    free_matrix(&expected_transpose);
    free_matrix(&sum);
    free_matrix(&scalar);
    free_matrix(&product);
    free_matrix(&transposed);
}

int main(){
    test_matrix();

    return 0;
}