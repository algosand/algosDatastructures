#include <bits/stdc++.h>
using namespace std;

/*
This is will convert a tokens for a ternary expression in C++ into a binary tree that then can be traversed
in a manner to return the result of the ternary expression.  Basically if current node is true you travel to the left
and else travel to the right.
*/

struct Node {
    int val;
    Node *left;
    Node *right;
};
Node *getTree(vector<string> tokens, int i) {
    Node *root = new Node;
    int val = tokens[i]=="true";
    root->val = val;
    if (i==tokens.size()-1) {return root;}
    i++;
    if (tokens[i]=="?") {
        i++;
        root->left = getTree(tokens, i);
        i++;
        root->right = getTree(tokens, i);
        return root;
    }
    return root;
}

bool solve(string s) {
    vector<string> tokens;
    istringstream ss(s);
    string word;
    while (ss >> word) {
        tokens.push_back(word);
    }
    Node *root = getTree(tokens, 0);
    bool res = false;
    while (root) {
        res = root->val;
        cout<<res<<endl;
        root = root->val ? root->left : root->right;
    }
    return res;
}