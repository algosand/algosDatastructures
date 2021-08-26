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
int main() {

}