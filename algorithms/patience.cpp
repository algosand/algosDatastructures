#include <bits/stdc++.h>
using namespace std;
/*
The patience sorting algorithm is named after a card game called patience, which without knowing the game
the major interesting component is how you can only place another card on top of another if it has a lower
card value.  
Similarly this idea can be used for the longest increasing subsequence problem where you store the sorted list
of smallest numbers, if you have a smaller number you can place it on top of the original value.  

This is just pseudocode to show, it is missing some components. 

Allows to solve LIS problem in O(nlogn) time. 

Use upper_bound if you are looking for longest non-decreasing subsequence
*/

int patience(vector<int>& A) {
    const int neutral = 1e5;
    int len = 0;
    vector<int> T(A.size(),neutral);
    for (int i = 0;i<A.size();i++) {
        int x = lower_bound(T.begin(), T.end(), A[i])-T.begin(); // binary search
        len = x+1;
        T[x] = A[i]; // update, it will replace larger values 
    }
    return len;
}

int main() {
    // read inputs here if desired. 
}