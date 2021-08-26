#include <bits/stdc++.h>
using namespace std;

/*
This is a particular type of dynamic programming problem that can be challenging, where you need to consider
multiple intervals and recurse on them, 

This first example shows a problem where we are saving the intervals, O(N^2) and we are saving the k which 
represents the count of adjacent duplicate values we can remove for points k*k, 
that gives O(N^3) but also you need to find all the next indices that have same value and increase k to consider those,


*/
vector<vector<vector<int>>> dp;
int recursion(int i, int j, int k, vector<int>& boxes) {
    if (i>j) {
        return 0;
    }
    if (i==j) {
        return k*k;
    }
    if (dp[i][j][k]!=0) {
        return dp[i][j][k];
    }
    int ans = k*k+recursion(i+1,j,1,boxes);
    for (int m = i+1;m<=j;m++) {
        if (boxes[i]==boxes[m]) {
            ans = max(ans, recursion(i+1,m-1,1,boxes)+recursion(m,j,k+1,boxes));
        }
    }
    return dp[i][j][k] = ans;
}
int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    dp.assign(n, vector<vector<int>>(n, vector<int>(n,0)));
    return recursion(0,n-1,1,boxes);
}

int main() {

}