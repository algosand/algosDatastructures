#include <bits/stdc++.h>
using namespace std;

// example of kruskal algorithm that works with a collection of 2-dimensional (cartesian points) in space to represent the location
// of the nodes to be connected. 

struct P {
    int x, y;
};

struct Edge {
    int i,j,w;
};

struct UnionFind {
    vector<int> parents, size;
    void init(int n) {
        parents.resize(n);
        iota(parents.begin(),parents.end(),0);
        size.assign(n,0);
    }

    int ufind(int i) {
        if (i==parents[i]) {
            return i;
        }
        return parents[i]=ufind(parents[i]);
    }

    bool uunion(int i, int j) {
        i = ufind(i), j = ufind(j);
        if (i!=j) {
            if (size[j]>size[i]) {
                swap(i,j);
            }
            size[i]+=size[j];
            parents[j]=i;
            return true;
        }
        return false;
    }
};

// manhattan distance cost function
int cost(const P &a, const P &b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int solve(vector<vector<int>>& pois) {
    vector<Edge> graph;
    vector<P> points;
    int n = pois.size();
    for (int i = 0;i<n;i++) {
        points.push_back(P{pois[i][0],pois[i][1]});
    }
    int minCost = 0;
    for (int i = 0;i<n;i++) {
        for (int j = i+1;j<n;j++) {
            graph.push_back(Edge{i,j,cost(points[i],points[j])});
            graph.push_back(Edge{j,i,cost(points[j],points[i])});
        }
    }
    sort(graph.begin(), graph.end(), [](const Edge &a, const Edge &b){
        return a.w < b.w;
    });
    UnionFind ds;
    ds.init(n);
    for (auto edge : graph) {
        if (ds.uunion(edge.i,edge.j)) {
            minCost += edge.w;
        }
    }
    return minCost;
}

/*
Kruskal's algorithm with minimum spanning tree (MST)
1. Array of weighed edges sorted in ascending order w.r.t. the weight. 
2. UnionFind datastructure to detect cycles

Detect cycles to determine if you should union two disjoint sets.  And to maintain
the tree structure in the result.  
Sort the edges to force the "minimum"
*/


/*
Another algorithm for cycle detection that fits some scenarios, when you want to detect a cycle and return false
is to use dfs, with backtracking components, this is a really good example where you want to use dfs to detect cycle

This algorithm detects a cycle in the dfs and is checking for arbitrage, that is if rate>visited[src].  So you 
were able to return to a previous node via a cycle and it has a larger value, that is arbitrage.  
In this case I want to return false if it detects arbitrage, so while it will detect cycle, it doesn't care about that.  
Can also be used to check if a graph is a DAG, that is directed acyclic graph.  
*/

unordered_map<string, vector<pair<string,double>>> graph;
unordered_map<string,double> visited;
double ans;
string target;
bool dfs(double rate, string src) {
    if (src==target) {
        ans = max(ans, rate);
    }
    if (visited.find(src)!=visited.end()) {
        return rate<=visited[src];
    }
    visited[src]=rate;
    for (auto &[nsrc,nrate]:graph[src]) {
        if (!dfs(rate*nrate, nsrc)) {
            return false;
        }
    }
    visited.erase(src);
    return true;
}
double solve(string source, string targ, vector<string>& sources, vector<string>& targets, vector<double>& rates) {
    visited.clear();
    graph.clear();
    int n = sources.size();
    for (int i = 0;i<n;i++) {
        graph[sources[i]].emplace_back(targets[i], rates[i]);   
    }
    ans = 0;
    target = targ;
    if (!dfs(1,source)) {
        return -1;
    }
    return ans;
}

/*


*/