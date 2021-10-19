#include <bits/stdc++.h>
using namespace std;

/*
There seems to be many variations of shortest path problems.  This file shows examples of shortest path problems
*/

/*
This first shortest path problem can be solved with BFS algorithm because it is an unweighted graph.  In this problem we actually want to find
strictly the second shortest path.  This requires bfs from node=1 and from node=n, 

https://leetcode.com/problems/second-minimum-time-to-reach-destination
*/
const int INF = 1e9;
int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<int> dist(n+1,INF);
    queue<int> q;
    vector<vector<int>> graph(n+1);
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    q.push(1); // (node, time, parent)
    int node;
    dist[1]=0;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (int &nei : graph[node]) {
            if (dist[node]+1<dist[nei]) {
                dist[nei]=dist[node]+1;
                q.push(nei);
            }
        }
    }
    q.push(n);
    vector<int> dist2(n+1,INF);
    dist2[n]=0;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (int &nei : graph[node]) {
            if (dist2[node]+1<dist2[nei]) {
                dist2[nei]=dist2[node]+1;
                q.push(nei);
            }
        }
    }
    int ans = INF;
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        if (dist[u]+dist2[v]+1>dist[n]) {
            ans = min(ans, dist[u]+dist2[v]+1);
        }
        if (dist2[u]+dist[v]+1>dist[n]) {
            ans = min(ans, dist2[u]+dist[v]+1);
        }
    }
    int t = 0;
    for (int i = 0;i<ans;i++) {
        if ((t/change)%2!=0) {
            t = (t/change+1)*change;
        }
        t = t + ((t/change)%2!=0 ? t%change : time);
    }
    return t;
}

/*
This is a 0-1 bfs to find shortest path on a graph that has edges with weights 0 or 1,  basic idea is to push anything with weigh t0 to the front of a deque and anything with weight 1 to the back of the deque. 

https://binarysearch.com/problems/Cheapest-Bus-Route
*/


const int INF = 1e4;
int solve(vector<vector<int>>& connections) {
    int n = 0, m = 0;
    unordered_map<int,unordered_map<int,vector<int>>> graph; // (from->to-> vector of bus)
    deque<vector<int>> q; // (bus, node, cost)
    for (auto &vec : connections) {
        n = max({n,vec[0],vec[1]});
        m = max(m, vec[2]);
        graph[vec[0]][vec[1]].push_back(vec[2]);
    }
    vector<vector<int>> dp(m+1, vector<int>(n+1,INF)); // bus->node -> mincost
    q.push_front({-1,0,0});
    while (!q.empty()) {
        int bus, station, cost;
        auto vec = q.front();
        bus = vec[0], station=vec[1], cost=vec[2];
        if (station==n) {
            return cost;
        }
        q.pop_front();
        for (auto &[to, busses] : graph[station]) {
            for (int &nbus : busses) {   
                int ncost = cost+(nbus!=bus);
                if (nbus==bus && dp[nbus][to]>ncost) {
                    q.push_front({nbus, to,ncost});
                    dp[nbus][to]=ncost;
                } else if (nbus!=bus && dp[nbus][to]>ncost) {
                    q.push_back({nbus, to,ncost});
                    dp[nbus][to] = ncost;
                }
            }
        }
    }
    return -1;
}