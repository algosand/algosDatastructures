#include <bits/stdc++.h>
using namespace std;
/*
General example of an unbounded knapsack problem.  


This is a problem where you have a list of items that have weights and values.  We need to fill 
up the entire knapsack with the items.  We can arrange them in a way that the sum(weights)=capacity.
But you have an infinite supply of every item.  

We want to maximize the value of the items that we store in the knapsack for this specific example.  

There are variations of this problem, sometimes you may want to minimize something.  it doesn't have to be
the value of the item but maybe the count of items you use to fill up the knapsack.  
*/
int unboundedKnapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity+1,INF);
    dp[0]=0; // base case
    for (int i = 0;i<=capacity;i++) {
        for (int j = 0;j<n;j++) {
            if (i<=weights[j]) {
                dp[i] = max(dp[i], values[j]+dp[i-weights[j]]);
            }
        }
    }
    return dp[capacity];
}
int main() {

}