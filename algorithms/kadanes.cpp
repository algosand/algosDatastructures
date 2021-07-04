#include <bits/stdc++.h>
using namespace std;
/*
Kadane's algorithm can find the maximum contiguous subarray sum for an array in O(n) time.  
It fits in the dynamic programming category, where you are basically keeping track of subproblems with
the sum up to jth index, and then it will save the sum from ith to jth index. 
sum = best up to (i-1)th index + arr[i], so you are computing the best to to the ith index. 
if the current value is better than the sum, you want to start over and update the left endpoint to be there. 
so now you can ay it is the sum = best_sum from jth to (i-1th) index + arr[i]. 
*/

int kadane(vector<int>& arr) {
    int n = arr.size(), sum = 0, res = 0;
    for (int i = 0;i<n;i++) {
        sum += arr[i];
        if (arr[i]>sum) {
            sum = arr[i];
        }
        res = max(sum, res);
    }
    return res;
}

int main() {
    int x, n;
    cin>>n;
    vector<int> arr;
    while (n--) {
        cin>>x;
        arr.push_back(x);
    }

}