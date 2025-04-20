# Matrix Library Project

## AUTHORING
- **Author:** Connor Myers
- **Affiliation:** UMBC / CMSC 313 - Section 04, 10am, Spring 2025
- **Date:** 04/19/2025

## PURPOSE OF SOFTWARE
This project implements a basic matrix libarary with support for the following operations:
- Matrix Addition
- Scalar Multiplication
- Matrix Multiplication
- Tranposistion

The project supports both **C** and **C++**

## FILES
**C Version**
- `matrix.h`   - Declaration of the Matrix struct and matrix operations
- `matrix.c`   - Implementation of the matric operations
- `maint.c`    - Executes the main equation `D = A + (# * B) * C`
- `test.c`     - Tests to verify the correctness of the matrix operations

**C++ Version**
- `matrix.hpp` - Declaration of the Matrix class
- `matrix.cpp` - Implementation of the matric class methods
- `main.cpp`   - Executes the main equation `D = A + (# * B) * C`
- `test.cpp`   - Tests to verify the correctness of the matrix operations

**BUILD**
- `makefile`   - Build script for compiling both C & C++ version

## BUILD INSTRUCTIONS
Run `make` to compile all programs

To compile individual targets:
     make maincpp   - C++ main
     make testcpp   - C++ tests
     make mainc     - C main
     make testc     - C tests


## TESTING METHODOLOGY
Both the **C** and **C++** implementations are verified with tests to ensure:
- Matrix sizes are correct after each operation
- Matrix values match expected results

**Each test prints out in the following form:**

`Testing [operation] matrix size: True/False`
`Testing [operation] values: True/False`

Operations tested include:
- Matrix addition
- Scalar multiplication
- Matrix multiplication
- Transposition

The `main.c` and `main.cpp` run the test of the following matrix expression:

D = A + (# * B) * C

Where:

A = [6, 4
     8, 3]

B = [1, 2, 3
     4, 5, 6]

C = [2, 4, 6
     1, 3, 5]

The output of D is then printed to the console for verification

**Expected output:**

     Resulting Matrix D:
     90 70
     200 150