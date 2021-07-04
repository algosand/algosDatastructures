#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> 2DprefixSum(vector<vector<int>>& matrix) {
    int R = matrix.size(), C = matrix[0].size();
    vector<vector<int>> prefix(R+1, vector<int>(C+1,0));
    for (int i = 1;i<=R;i++) {
        for (int j = 1;j<=C;j++) {
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+matrix[i-1][j-1];
        }
    }
    return prefix;
}

int main() {
    int R, C, x;
    cin>>R>>C;
    vector<vector<int>> matrix(R, vector<int>(C,0));
    for (int i = 0;i<R;i++) {
        for (int j = 0;j<C;j++) {
            cin>>x;
            matrix[i][j]=x;
        }
    }
    vector<vector<int>> prefix = 2DprefixSum(matrix);
}