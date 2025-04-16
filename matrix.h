// matrix.h

#ifndef matrix_h
#define matrix_h

#include <stddef.h>

typedef struct{
    int** data;
    size_t rows;
    size_t cols;
} Matrix;

Matrix create_matrix(size_t rows, size_t cols);
Matrix from_array(int** values, size_t rows, size_t cols);
Matrix add_matrix(const Matrix* a, const Matrix* b);
Matrix multiply_matrix(const Matrix* a, const Matrix* b);
Matrix scalar_matrix(const Matrix* a, int scalar);
Matrix transpose_matrix(const Matrix* a);
void print_matrix(const Matrix* a);
void free_matrix(Matrix* a);

#endif