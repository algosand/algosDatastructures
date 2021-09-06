#include <bits/stdc++.h>
using namespace std;
/*
This is a good example of dp on a tree, that uses a post order traversal and a preorder traversal.

*/
class Solution {
public:
    vector<int> count, sum;
    vector<vector<int>> graph;
    int N;
    void postOrder(int node = 0, int parent = -1) {
        for (int child : graph[node]) {
            if (child==parent) {continue;}
            postOrder(child, node);
            count[node]+=count[child];
            sum[node]+=sum[child]+count[child];
        }
    }
    void preOrder(int node = 0, int parent = -1) {
        for (int child : graph[node]) {
            if (child==parent) {continue;}
            sum[child] = sum[node]-count[child]+(N-count[child]);
            preOrder(child, node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        count.assign(n, 1);
        sum.assign(n,0);
        graph.resize(n);
        N = n;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        postOrder();
        preOrder();
        return sum;
    }
};