#include <bits/stdc++.h>
using namespace std;
// A general UnionFind datastructure template

struct UnionFind {
    vector<int> parent, sizes;
    void init() {
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

// Another template for UnionFind where you can use vectors that store the index of unique nodes or index to a point.
struct UnionFind2 {
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

// Union find trick for when you are in 2-Dimensions, a method to represent it as a single integer for the union us this
int getId(int row, int col, int ncols) {
    return row*ncols+col;
}

// Union find in 3-dimensions?

