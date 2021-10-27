#include <bits/stdc++.h>
using namespace std;

/*
The longest increasing subsequence is an interesting dp problem that can be solved in O(n^2) and O(nlogn).  
Here I'm going to look at n^2, and the nlogn solution called patience algorithm.

It is a classical problem and many other problems build on it or use some variation of it.  
*/


int LIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<i;j++) {
            if (nums[i]>nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
/*
This one runs in O(nlogn) 
*/
const int NEUTRAL = 1e5;
int patience(vector<int>& A) {
    int len = 0;
    vector<int> T(A.size(),NEUTRAL);
    for (int i = 0;i<A.size();i++) {
        int x = lower_bound(T.begin(), T.end(), A[i])-T.begin(); // binary search
        len = max(len, x+1);
        T[x] = A[i]; // update, it will replace larger values 
    }
    return len;
}
