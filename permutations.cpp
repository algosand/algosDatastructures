#include <bits/stdc++.h>
using namespace std;
/*
Simple brute force recursive algorithm to get all the permutations of an array.
Assuming the array contains distinct integers.

test input: 5 0 1 2 3 4
*/
vector<int> arr;
vector<vector<int>> parrs;
void getPermutations(int i, vector<int> perm, unordered_set<int> vis) { 
    int n = arr.size();
    if (i==n) {
        parrs.push_back(perm);
        return;
    }
    for (int j = 0;j<n;j++) {
        if (vis.count(j)>0) {continue;}
        perm.push_back(arr[j]);
        vis.insert(j);
        getPermutations(i+1,perm, vis);
        perm.pop_back();
        vis.erase(j);
    }
}

int main() {
    int N, x;
    cin>>N;
    while (N--) {
        cin>>x;
        arr.push_back(x);
    }
    getPermutations(0, {}, {});
    for (int i = 0;i<parrs.size();i++) {
        printf("the %d permutation\n[", i+1);
        for (int y : parrs[i]) {
            printf("%d, ", y);
        }
        printf("]\n");
    }
}