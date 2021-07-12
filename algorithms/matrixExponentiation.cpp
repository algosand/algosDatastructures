#include <bits/stdc++.h>
using namespace std;

// look at math/matrix.cpp to see the Matrix struct in more details  
struct Matrix {
    int numRows, numCols;

    void neutral(int rows, int cols) {
        printf("look at math/matrix.cpp for the actual code for matrix")
    }
};
// matrix exponentiation
Matrix matrix_power(Matrix& A, int b) {
    Matrix result;
    result.neutral(A.numRows, A.numCols);
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result*A);
        }
        A *= A;
        b /= 2;
    }
    return result;
}