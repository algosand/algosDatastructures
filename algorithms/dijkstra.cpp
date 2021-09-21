#include <bits/stdc++.h>
using namespace std;
/*
Example of dijkstra algorithm applied to a matrix to find the shortest path.
It's more like finding the minimum cost path but based on the maximum
absolute difference of adjacent cells. 
*/
const int INF = 1e9;
const vector<pair<int,int>> DIRECTIONS = {{1,0},{0,1},{-1,0},{0,-1}};
int dijkstra(vector<vector<int>>& matrix) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    int R = matrix.size(), C = matrix[0].size();
    vector<vector<int>> dist(R, vector<int>(C,INF));
    int v, r, c;
    minHeap.push({0, 0, 0});
    dist[0][0]=0;
    auto check = [&](const int i, const int j) {
        return i>=0 && i<R && j>=0 && j<C;
    };
    while (!minHeap.empty()) {
        auto vec = minHeap.top();
        minHeap.pop();
        v = vec[0], r = vec[1], c=vec[2];
        if (r==R-1 && c==C-1) {
            break;
        }
        for (auto &[dr, dc] : DIRECTIONS) {
            int nr = r + dr, nc = c + dc;
            if (check(nr, nc) && max(v, abs(matrix[r][c]-matrix[nr][nc])) < dist[nr][nc]) {
                minHeap.push({max(v, abs(matrix[r][c]-matrix[nr][nc])), nr, nc});
                dist[nr][nc] = max(v, abs(matrix[r][c]-matrix[nr][nc]));
            }
        }
    }
    return dist[R-1][C-1];
}

/*
Example of dijkstra problem for finding the shortest path from a single source to a single destination node.
This time we create a graph that consists of all edges with weight 1.  This is to signify that between s[i:j] 
there is a palindrome.  This way we can find the shortest path through the string while minimizing
the number of palindromic substrings we can split it, in order to get to the last index. 

It is much easier to understand this solution by drawing out the graph in my opinion. 
*/

const int INF  = 1e7;
int solve(string s) {
    int n = s.size();
    unordered_map<int, vector<int>> palin;
    palin[0].push_back(1);
    auto expand = [&](int i, int j) {
        while (i>=0 && j<n && s[i]==s[j]) {
            palin[i].push_back(j+1);
            i--;
            j++;
        }
    };
    for (int i = 1;i<n;i++) {
        expand(i,i);
        expand(i-1,i);
    }
    vector<int> dist(n+1,INF);
    dist[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;  // min heap
    q.emplace(0,0);
    while (!q.empty()) {
        int i, d;
        tie(d,i) = q.top();
        if (i==n) {
            return d;
        }
        q.pop();
        for (int j : palin[i]) {
            if (d+1<dist[j]) {
                q.emplace(d+1,j);
                dist[j]=d+1;
            }
        }
    }
    return -1;
}