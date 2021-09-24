#include <bits/stdc++.h>
using namespace std;
/*
This is a good example of a problem that is dp on a tree.  

Basically we store the values for if we take or leave a node.  This is a problem where you 
Given a binary tree root, return the maximum sum of the integers that can be obtained given no 
two integers can be adjacent parent to child.

Supposedly similar to a knapsack problem 
*/
class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
    };
int ans;
vector<int> dfs(Tree* root) {
    if (root==nullptr) {
        return {0,0};
    }
    vector<int> left = dfs(root->left), right = dfs(root->right);
    int take = left[1]+right[1] + root->val, leave = max(left[0], left[1]) + max(right[0], right[1]);
    ans = max({ans, take, leave});
    return {take, leave};
}
int solve(Tree* root) {
    ans = 0;
    dfs(root);
    return ans;
}