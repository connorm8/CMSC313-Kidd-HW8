// matrix.c

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix create_matrix(size_t rows, size_t cols){
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int**)malloc(rows * sizeof(int*));
    for(size_t i = 0; i < rows; i++){
        m.data[i] = (int*)calloc(cols, sizeof(int));
    }

    return m;
}

Matrix from_array(int** values, size_t rows, size_t cols){
    Matrix m = create_matrix(rows, cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            m.data[i][j] = values[i][j];
        }
    }

    return m;
}

Matrix add_matrix(const Matrix* a, const Matrix* b){
    Matrix result = create_matrix(a->rows, a->cols);
    for(size_t i = 0; i < a->rows; i++){
        for(size_t j = 0; j < a->cols; j++){
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return result;
}

Matrix multiply_matrix(const Matrix* a, const Matrix* b){
    Matrix result = create_matrix(a->rows, a->cols);
    for(size_t i = 0; i < a->rows; i++){
        for(size_t j = 0; j < b->cols; j++){
            for(size_t k = 0; k < a->cols; k++){
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}

Matrix scalar_matrix(const Matrix* a, int scalar){
    Matrix result = create_matrix(a->rows, a->cols);
    for(size_t i = 0; i < a->rows; i++){
        for(size_t j = 0; j < a->cols; j++){
            result.data[i][j] = a->data[i][j] * scalar;
        }
    }

    return result;
}

Matrix transpose_matrix(const Matrix* a){
    Matrix result = create_matrix(a->cols, a->rows);
    for(size_t i = 0; i < a->rows; i++){
        for(size_t j = 0; j < a->cols; j++){
            result.data[j][i] = a->data[i][j];
        }
    }

    return result;
}

void print_matrix(const Matrix* a){
    for(size_t i = 0; i < a->rows; i++){
        for(size_t j = 0; j < a->cols; j++){
            printf("%d ", a->data[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(Matrix* a){
    for(size_t i = 0; i < a->rows; i++){
        free(a->data[i]);
    }
    free(a->data);
    a->data = NULL;
    a->rows = 0;
    a->cols = 0;
}