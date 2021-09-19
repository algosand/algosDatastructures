#include <bits/stdc++.h>
using namespace std;

/*
This is a classical problem that is np-complete, and it is a variation of the multiple subset sum 
problem and the knapsack problem. 

Subset sum problem is a decision problem in computer science.  

In general you have a multiset S of integers and at target sum T, and you want to dteermine if any subset
of the integers sum to exactly T.  

Now notice for the variation below it is more like we have many target sums, that is if we assume that the maximum
sum for taking all coins is very small we can just do this in O(sum) space and store [1,2,3,...sum] targets.  We want
to see if we can sum to any target in the range between 1 and the maximum sum. 

below this is called mx, 

Then we just need to iterate through all coins, the number of times the quantity appears, as long as 
number of coins and the sum(quantities) remain small this is not that too slow. 


In terms of it's relationship to knapsack problem.  The knapsack is considered a generalization of SSP in which 
each input item has both a value and weight.  (actually the one below is somewhat like that we have a 
value and a weight), but the difference is that in knapsack the goal of the problem is to maximize the value such 
that total weight is bounded.  

This is an optimization problem because it is NP-complete and normally for large inputs it will be exponential
*/
int subsetSum(vector<int>& coins, vector<int>& quantities) {
    int mx = 0, n = coins.size();
    for (int i = 0;i<n;i++) {
        mx += (coins[i]*quantities[i]);
    }
    vector<bool> sums(mx+1, false);
    sums[0]=true;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<quantities[i];j++) {
            for (int sum = mx;sum>=coins[i];sum--) {
                sums[sum] = sums[sum] || sums[sum-coins[i]];
            }
        }
    }
    return accumulate(sums.begin(), sums.end(),-1);
}