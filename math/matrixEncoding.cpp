#include <bits/stdc++.h>
using namespace std;
/*
You can encode diagonals by using the following trick with a hashtable
[
[0,1,2],
[-1,0,1],
[-2,-1,0]
]
you just take row - col, 
example below for adding them to a set the values
*/
int diagonal(vector<vector<int>>& matrix) {
    int R = matrix.size(), C = matrix[0].size();
    unordered_map<int, unordered_set<int>> mp;
    for (int i = 0;i<R;i++) {
        for (int j = 0;j<C;j++) {
            mp[i-j].insert(matrix[i][j]);
        }
    }
}
int main() {

}