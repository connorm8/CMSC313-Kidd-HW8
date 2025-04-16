# Matrix Library Project

## AUTHORING
- **Author:** Connor Myers
- **Affiliation:** UMBC / CMSC 313 - Section 04, 10am, Spring 2025

## PURPOSE OF SOFTWARE
This project implements a basic matrix libarary with support for the following operations:
- Matrix Addition
- Scalar Multiplication
- Matrix Multiplication
- Tranposistion

The project supports both **C** and **C++**

## FILES
- `makefile`   - Build script for compiling both C & C++ version

**C Version**
- `matrix.h`   - Declaration of the Matrix struct and matrix operations
- `matrix.c`   - Implementation of the matrix operations
- `maint.c`    - Test program

**CPP Version**
- `matrix.hpp` - Declaration of the Matrix class
- `matrix.cpp` - Implementation of the matrix class methods
- `main.cpp`   - Test Program

## BUILD INSTRUCTIONS
With the makefile, running 'make mainc' or 'make maincpp' can be used to build both the C and C++ versions respectively

To run the files run 'mainc' or 'maincpp' to run either the C or the C++ build

## TESTING METHODOLOGY
The main.c and main.cpp run the test of the following matrix expression:

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
