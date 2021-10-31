#include <bits/stdc++.h>
using namespace std;

/*
This is an example of a prefix sum algorithm, For this one the prefix sum 
is being used to store the count of '|' character processed int he string.  This is one way prefix sum can be 
used, then it is queried to find the count of '|' in a range.  
*/

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<int> psum(n+1,0), prev(n+1,0), next(n+1,0);
    for (int i = 0;i<n;i++) {
        psum[i+1] = psum[i] + (s[i]=='|');
        prev[i+1] = s[i]=='|' ? i : prev[i];
    }
    for (int i = n-1;i>=0;i--) {
        next[i] = s[i]=='|' ? i : next[i+1];
    }
    vector<int> ans;
    for (auto &q : queries) {
        int leftmost = next[q[0]], rightmost = prev[q[1]+1];
        ans.push_back(rightmost>leftmost ? rightmost-leftmost - (psum[rightmost]-psum[leftmost]) : 0);
    }
    return ans;
}