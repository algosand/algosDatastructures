#include <bits/stdc++.h>
using namespace std;

/*
Perfect example of backtracking algorithm is the one for finding a solution to an incomplete sudoku board

*/

bool backtrack(stack<pair<int,int>>& cells, vector<vector<int>>& rows, vector<vector<int>>& cols, vector<vector<int>>& submatrices, vector<vector<int>>& matrix) {
    if (cells.empty()) {
        return true;
    }
    int r, c;
    tie(r,c) = cells.top();
    cells.pop();
    for (int dig = 0;dig<9;dig++) {
        if (rows[r][dig] || cols[c][dig] || submatrices[3*(r/3)+c/3][dig]) {continue;}
        rows[r][dig]=1;
        cols[c][dig]=1;
        submatrices[3*(r/3)+c/3][dig]=1;
        matrix[r][c]=dig+1;
        if (backtrack(cells, rows, cols, submatrices, matrix)) {
            return true;
        }
        rows[r][dig]=0;
        cols[c][dig]=0;
        submatrices[3*(r/3)+c/3][dig]=0;
        matrix[r][c]=0;
    }
    cells.emplace(r,c);
    return false;
}

vector<vector<int>> solve(vector<vector<int>>& matrix) {
    stack<pair<int,int>> emptyCells;
    vector<vector<int>> rows(9, vector<int>(9,0)), cols(9, vector<int>(9,0)), submatrices(9, vector<int>(9,0));
    for (int i = 0;i<9;i++) {
        for (int j = 0;j<9;j++) {
            if (matrix[i][j]==0) {
                emptyCells.emplace(i,j);
            } else {
                rows[i][matrix[i][j]-1]=1;
                cols[j][matrix[i][j]-1]=1;
                submatrices[3*(i/3)+j/3][matrix[i][j]-1]=1;
            }
        }
    }
    backtrack(emptyCells, rows, cols, submatrices, matrix);
    return matrix;
}