#include <bits/stdc++.h>
using namespace std;
// A general UnionFind datastructure template
template <class T>
class UnionFind
{
public:
    unordered_map<T, T> parent;
    unordered_map<T, int> size;
    void init() {
        parent.clear();
        size.clear();
    }

    T ufind(T u)
    {
        if (parent.count(u) == 0)
        {
            return parent[u] = u;
        }
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = ufind(parent[u]);
    }

    bool uunion(T u, T v)
    {
        u = ufind(u);
        v = ufind(v);
        if (u != v)
        {
            if (size[u] < size[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
            return false;
        }
        return true;
    }

    // checking if something is connected is to find the parents. 
    bool isConnected(T s, T e)
    {
        return ufind(s) == ufind(e);
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