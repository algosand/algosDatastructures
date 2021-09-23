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

/*
Example of how to use the prefix on a bounding box
*/
int total(int row0, int col0, int row1, int col1) {
    return prefix[row1+1][col1+1]-prefix[row1+1][col0]-prefix[row0][col1+1]+prefix[row0][col0];
}

/*
This is a good implementation of a 2d prefix sum problem being used.  

*/
void setmax(int &a, int b) {
    a = max(a,b);
}
int solve(vector<vector<int>>& matrix, int target) {
    int R = matrix.size(), C = matrix[0].size(), ans = 0;
    vector<vector<int>> prefix(R+1, vector<int>(C+1,0));
    for (int i = 0;i<R;i++) {
        for (int j = 0;j<C;j++) {
            prefix[i+1][j+1] = prefix[i][j+1]+prefix[i+1][j]-prefix[i][j]+matrix[i][j];
        }
    }
    for (int i = 1;i<=R;i++) {
        for (int j = 1;j<=C;j++) {
            for (int k = 0;k<=min(R-i,C-j);k++) {
                int sum = prefix[i+k][j+k]-prefix[i+k][j-1]-prefix[i-1][j+k]+prefix[i-1][j-1];
                if (sum<=target) {
                    setmax(ans,(k+1)*(k+1));
                }
            }
        }
    }
    return ans;
}