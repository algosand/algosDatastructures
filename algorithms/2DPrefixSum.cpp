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
int solve(vector<vector<int>>& matrix, int target) {
    int R = matrix.size(), C = matrix[0].size(), lo = 0, hi = min(R,C)+1;
    vector<vector<int>> prefix(R+1, vector<int>(C+1,0));
    for (int i = 0;i<R;i++) {
        for (int j = 0;j<C;j++) {
            prefix[i+1][j+1] = prefix[i][j+1]+prefix[i+1][j]-prefix[i][j]+matrix[i][j];
        }
    }
    auto isValid = [&](const int k) {
        for (int i = k;i<=R;i++) {
            for (int j = k;j<=C;j++) {
                int sum = prefix[i][j] -prefix[i][j-k] - prefix[i-k][j]+prefix[i-k][j-k];
                if (sum<=target) {return true;}
            }
        }
        return false;
    };
    while (lo<hi) {
        int mid = lo+hi+1>>1;
        if (isValid(mid)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return lo*lo;
}