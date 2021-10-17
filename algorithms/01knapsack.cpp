#include <bits/stdc++.h>
using namespace std;

/*
This is the 0-1 knapsack problem which is when you are given an array of values and weights for items that you can put into a knapsack.  You also have a capacity for the knapsack. You can take only 1 of the whole item and put it knapsack.  And you want to maximize the value in the knapsack

Below is a simple variation of the problem.  where you have capacity k, but you want to find the number of subsets that can achieve the capacity by summing the values. 


*/

const int MOD = 1e9+7;
int solve(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(k+1,0);
    dp[0]=1;
    for (int &num : nums) {
        for (int i = k;i>=num;i--) {
            dp[i] = (dp[i]+dp[i-num])%MOD;
        }
    }
    return dp.back();
}