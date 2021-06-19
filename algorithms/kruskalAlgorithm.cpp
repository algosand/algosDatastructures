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
        int ii = ufind(i), jj = ufind(j);
        if (ii!=jj) {
            if (size[jj]>size[ii]) {
                swap(ii,jj);
            }
            size[ii]+=size[jj];
            parents[jj]=ii;
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