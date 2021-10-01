#include <bits/stdc++.h>
using namespace std;

/*
This code is a super good example of recursion and backtracking algorithm that is a little tricky at first

*/
vector<char> ops = {'+', '-', '*', '/'};
int eval(int a, int b, char op) {
    switch(op) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        default:
            return a/b;
    }
}
vector<int> evaluateAll(vector<int>& nums, int left, int right) {
    if (left==right) {return {nums[left]};}
    vector<int> res;
    for (int i = left;i<right;i++) {
        vector<int> leftV = evaluateAll(nums, left, i);
        vector<int> rightV = evaluateAll(nums, i+1,right);
        for (int &u : leftV) {
            for (int &v : rightV) {
                res.push_back(u+v);
                res.push_back(u-v);
                res.push_back(u*v);
                if (v!=0) {res.push_back(u/v);}
            }
        }
    }
    return res;
}
bool solve(vector<int>& nums) {
    vector<int> all = evaluateAll(nums, 0, 3);
    for (int &sum : all) {
        printf("sum=%d\n", sum);
        if (sum==24) {return true;}
    }
    return false;
}