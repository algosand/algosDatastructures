#include <bits/stdc++.h>
using namespace std;

/*
Learning meet in the middle algorithm applied to algorithmic problems. Similar to divide and conquer but it is not recursively dividing the input. 

A problem for this is something like the following.  If you have an array of n numbers, how many ways can you choose a subset of numbers with sum x.

where the size of the array is n<=40, 
If you consider all possible subsets by brute force it would require O(2^n) or 2^40 which is very expensive algorithm.  Using meet in the middle can reduce that time complexity.  

1) split the original array into two divided_arrays A1, and A2 which will be size n/2.
2) compute all the subset sums for array A1 and A2, and return that array X but sorted (O(2^(n/2)nlog(n)))
3) Merge the sorted subset sums array X from both arrays, say they are X1 and X2.
4) Iterate through array X1 and binary search in array X2 O(2^(n/2)nlogn)
*/

vector<long long> subsetSums(vector<long long>& arr) {
    int n = arr.size();
    vector<long long> X;
    for (int i = 0;i<(1<<n);i++) {
        long long sum = 0;
        for (int j = 0;j<n;j++) {
            if ((i>>j)&1) {
                sum += arr[j];
            }
        }
        X.push_back(sum);
    }
    return X;
}

long long binarySearch(vector<long long>& arr, long long target) {
    return upper_bound(arr.begin(), arr.end(), target)-arr.begin()-1;
}

long long meetInMiddle(vector<int>& arr, long long target) {
    long long n = arr.size();
    vector<long long> left, right;
    for (int i = 0;i<n;i++) {
        if (i<n/2) {
            left.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
    }
    vector<long long> X = subsetSums(left), Y = subsetSums(right);
    sort(Y.begin(), Y.end());
    long long numWays = 0;
    for (long long &num : X) {
        int i = binarySearch(Y, target-num), j = binarySearch(Y, target-1-num);
        numWays += i-j;
    }
    return numWays;
}


int main () {
    int N, target, v;
    vector<int> arr;
    cin>>N>>target;
    while (N--) {
        cin>>v;
        arr.push_back(v);
    }
    cout<<meetInMiddle(arr, target);
}

/*
Meet in the middle to solve an interesting problem.  It was asking to find the min absolute difference between the sum of n elements and sum of the other n elements in an array of size 2*n.  So basically if you partition the array into two separate arrays, take the sum of those arrays and find the absolute difference.  The best is to achieve the target, so we do normal meet in middle, but need to return a 2d vector for the subsetSums, because we need subsetSums for when you have k elements, that way you can make sure you binarysearch the other array with the target to get the best sum with n-k elements from it.  
*/
const int INF = 1e9;
vector<vector<int>> subsetSums(vector<int>& arr) {
    int n= arr.size();
    vector<vector<int>> ret(n+1);
    for (int i = 0;i<(1<<n);i++) {
        int sum = 0, k = 0;
        for (int j = 0;j<n;j++) {
            if ((i>>j)&1) {
                sum += arr[j];
                k++;
            }
        }
        ret[k].push_back(sum);
    }
    return ret;
}
int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> left, right;
    int sum = 0;
    for (int i = 0;i<n;i++) {
        if (i<n/2) {
            left.push_back(nums[i]);
        } else {
            right.push_back(nums[i]);
        }
        sum += nums[i];
    }
    vector<vector<int>> X = subsetSums(left), Y = subsetSums(right);
    for (vector<int> &y : Y) {
        sort(y.begin(), y.end());
    }
    int target = sum/2,ans = INF, other;
    for (int k = 0;k<=n/2;k++) {
        for (int i = 0;i<X[k].size();i++) {
            int j = upper_bound(Y[n/2-k].begin(), Y[n/2-k].end(), target-X[k][i])-Y[n/2-k].begin();
            if (j<Y[n/2-k].size()) {
                other = sum - (X[k][i]+Y[n/2-k][j]);
                ans = min(ans, abs(X[k][i]+Y[n/2-k][j]-other));
            }
            if (j>0) {
                other = sum - (X[k][i]+Y[n/2-k][j-1]);
                ans = min(ans, abs(X[k][i]+Y[n/2-k][j-1]-other));
            }
        }
    }
    return ans;
}
