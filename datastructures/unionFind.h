#include <bits/stdc++.h>
using namespace std;
// A general UnionFind datastructure template

struct UnionFind {
    vector<int> parent, sizes;
    void init(int n) {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        sizes.assign(n,1);
    }

    int find(int i)
    {
        if (i==parent[i]) {
            return i;
        }
        return parent[i]=find(parent[i]);
    }

    bool uunion(int i, int j)
    {
        i = find(i), j=find(j);
        if (i!=j) {
            if (sizes[j]>sizes[i]) {
                swap(i,j);
            }
            parent[j]=i;
            sizes[i]+=sizes[j];
            return true;
        }
        return false;
    }

    // checking if something is connected is to find the parents. 
    bool isConnected(int s, int e)
    {
        return find(s) == find(e);
    }
};

// Union find trick for when you are in 2-Dimensions, a method to represent it as a single integer for the union us this
int getId(int row, int col, int ncols) {
    return row*ncols+col;
}

// Union find in 3-dimensions?
