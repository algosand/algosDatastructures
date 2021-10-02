#include <bits/stdc++.h>
using namespace std;
/*
The classic LCS problem that can be solved with this O(n^2) dp or it can be solved with the 
O(nlogn) patience aglorithm.
*/
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            if (text1[i]==text2[j]) {
                dp[i+1][j+1]=dp[i][j]+1;
            } else {
                dp[i+1][j+1]=max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[n][m];
}