// main.cpp

#include "matrix.hpp"
#include <vector>

int main(){

    Matrix A(std::vector<std::vector<int>>{{6, 4}, {8, 3}});
    Matrix B(std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}});
    Matrix C(std::vector<std::vector<int>>{{2, 4 ,6}, {1, 3, 5}});

    Matrix D = A + (B * 3) * C.transpose();

    std::cout << "Resulting Matrix D:\n";
    D.print();

    return 0;
}