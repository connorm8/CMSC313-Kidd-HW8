// test.cpp

#include "matrix.hpp"
#include <cassert>
#include <iostream>

void print_testcase(const Matrix& actual, const Matrix& expected, const std::string& label){
    bool values_correct = false;

    if(actual.getRows() != expected.getRows() || actual.getCols() != expected.getCols()){
        std::cout << "Testing " << label << " matrix size: False\n";
    }else{
        std::cout << "Testing " << label << " matrix size: True\n";

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(actual.getValue(i, j) != expected.getValue(i, j)){
                    values_correct = false;
                }
            }
        }

        values_correct = true;
    }

    std::cout << "Testnig " << label << " values: " << (values_correct ? "True" : "False") << "\n";
}

void test_matrix(){

    Matrix A({{1, 2}, {3, 4}});
    Matrix B({{5, 6}, {7, 8}});

    // Test Addition
    Matrix expected_sum({{6, 8}, {10, 12}});
    Matrix sum = A + B;
    print_testcase(sum, expected_sum, "addition");

    // Test Scalar Multiplication
    Matrix expected_scaled({{2, 4}, {6, 8}});
    Matrix scaled = A * 2;
    print_testcase(scaled, expected_scaled, "scalar multiplication");


    // Test Matrix Multiplication
    Matrix expected_product({{19, 22}, {43, 50}});
    Matrix product = A * B;
    print_testcase(product, expected_product, "matrix multiplication");

    // Test Transposition
    Matrix expected_transpose({{1, 3}, {2, 4}});
    Matrix transposed = A.transpose();
    print_testcase(transposed, expected_transpose, "tranpose");

}

int main(){
    test_matrix();

    return 0;
}