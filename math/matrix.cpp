#include <bits/stdc++.h>
using namespace std;

// Often times the numbers will get too large and overflow in C++, so we need to MOD it. 
int MOD = 1e9 + 7;
struct Matrix {
    int numRows, numCols;
    vector<vector<int>> M;
    // initialize the 2-dimensional array representation for the matrix with 
    // a given value. 
    void init(int r, int c, int val) {
        numRows = r, numCols = c;
        M.resize(r);
        for (int i = 0;i<r;i++) {
            M[i].assign(c, val);
        }
    }
    // neutral matrix is just one's along the main diagonal (identity matrix)
    void neutral(int r, int c) {
        numRows = r, numCols = c;
        M.resize(r);
        for (int i = 0;i<r;i++) {
            M[i].assign(c, 0);
        }
        for (int i = 0;i<r;i++) {
            for (int j = 0; j < c;j++) {
                if (i==j) {
                    M[i][j]=1;
                }
            }
        }

    }
    // Set's a pair of coordinates on the matrix with the specified value, works for a transition matrix
    // where you need ones in places. 
    void set(vector<pair<int,int>> locs, int val) {
        int r, c;
        for (auto loc : locs) {
            tie(r, c) = loc;
            M[r][c] = val;
        }
    }
    // this matrix times another matrix. 
    void operator*=(const Matrix& B) {
        int RB = B.M.size(), CB = B.M[0].size();
        vector<vector<int>> result(numRows, vector<int>(CB, 0));
        for (int i = 0;i < numRows;i++) {
            for (int j = 0;j < CB;j++) {
                int sum = 0;
                for (int k = 0;k < RB;k++) {
                    sum = (sum + ((long long)M[i][k]*B.M[k][j])%MOD)%MOD;
                }
                result[i][j] = sum;
            }
        }
        numRows = numCols, numCols = RB;
        swap(M, result);
    }

    void transpose() {
        int R = numCols, C = numRows;
        vector<vector<int>> matrix(R, vector<int>(C,0));
        for (int i = 0;i < numRows;i++) {
            for (int j = 0;j < numCols;j++) {
                matrix[j][i]=M[i][j];
            }
        }
        swap(numRows,numCols); // transpose swaps the rows and columns
        swap(M,matrix); // swap these two
    }

    // Method to convert a row and column to a unique integer that identifies a row, column combination
    // that can be used in hashing
    int getId(int row, int col) {
        return numRows*row+col;
    }
};

Matrix operator*(const Matrix& A, const Matrix& B) {
    int RA = A.M.size(), CA = A.M[0].size(), RB = B.M.size(), CB = B.M[0].size();
    if (CA!=RB) {
        printf("CA and RB are not equal\n");
        return A;
    }
    Matrix result;
    result.init(RA,CB,0);
    for (int i = 0;i < RA;i++) {
        for (int j = 0; j < CB; j++) {
            int sum = 0;
            for (int k = 0;k < RB;k++) {
                sum = (sum+((long long)A.M[i][k]*B.M[k][j])%MOD)%MOD;
            }
            result.M[i][j]=sum;
        }
    }
    return result;
}

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

/*
A = TB

How to derive the Transition and base matrix

Create a matrix 


*/

int main() {
    // example of how to use matrix exponentiation
    // This will not really work as it doesn't have all the inputs.  
    int n;
    Matrix transition, base;
    transition.init(5, 5, 0);
    base.init(5, 1, 1);
    vector<pair<int,int>> ones = {{0,1}, {0, 2}, {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 3}, {3, 2}, {4, 2}, {4, 3}};
    transition.set(ones, 1);
    Matrix expo = matrix_power(transition, n-1); // exponentiated transition matrix
    Matrix result = expo*base;
    result.transpose();
    int sum = 0;
    for (int i = 0;i<5;i++) {
        sum = (sum+result.M[0][i])%MOD;
    }
    return sum;
}