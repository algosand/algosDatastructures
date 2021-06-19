#include <bits/stdc++.h>
using namespace std;

// Segment tree data structure 
struct Segtree {
    int size;
    vector<int> tree;
    void init(int n) {
        size = 1;
        while (size<n) {
            size*=2;
        }
        tree.assign(2*size,0);
    }
    void update(int i, int val)
    {
        tree[base + i] = val;
        for (int x = base + i >> 1; x >= 1; x >>= 1)
        {
            tree[x] = tree[x << 1] + tree[(x << 1) ^ 1];
        }
    }

    long long int query(int r)
    {
        if (r < 0)
        {
            return 0;
        }
        long long int res = tree[base + r];
        for (int x = base + r; x != 1; x >>= 1)
        {
            if ((x & 1) > 0)
            {
                res += tree[x - 1];
            }
        }
        return res;
    }

    long long int range(int l, int r)
    {
        return query(r - 1) - query(l - 1);
    }

}


// Segment tree data structure with lazy propagation (Used when need to update a range rather than a single node)

struct Segtree {
    
    int size;
    vector<int> tree;
    vector<int> lazy;
    
    void init(int n) {
        size = 1;
        while (size<n) {
            size*=2;
        }
        tree.assign(2*size,INT_MAX);
        lazy.assign(2*size,INT_MAX);
    }
    
    void updateLazy(int srange, int erange, int delta, int low, int high, int pos)
    {
        // See if all propagation is done at pos, if not update tree
        // at pos and mark its children for lazy propagation. 
        if (lazy[pos] != INT_MAX) {
            tree[pos] = min(tree[pos], lazy[pos]);
                if (low != high) {  // not a leaf node
                    lazy[2*pos+1] = min(lazy[pos], lazy[2*pos+1]);
                    lazy[2*pos+2] = min(lazy[pos], lazy[2*pos+2]);
                }
            lazy[pos] = INT_MAX;
        }
        // no overlap condition
        if (srange > high || erange < low) {
            return;
        }
        
        // total overlap condition
        if (srange <= low && erange >= high) {
            tree[pos] = min(tree[pos], delta);
            if (low != high) {
                lazy[2*pos+1] = min(delta, lazy[2*pos+1]);
                lazy[2*pos+2] = min(delta, lazy[2*pos+2]);
            }
            return;
        }
        
        // else partial overlap and look both left and right
        int mid = (low+high)>>1;
        updateLazy(srange,erange,delta,low,mid,2*pos+1);
        updateLazy(srange,erange,delta,mid+1,high,2*pos+2);
        tree[pos] = min(tree[2*pos+1],tree[2*pos+2]);
    }
    
    int queryLazy(int qlow, int qhigh, int low, int high, int pos) {
        if (lazy[pos] != INT_MAX) {
            tree[pos] = min(lazy[pos],tree[pos]);
            if (low!=high) { // not a leaf node
                lazy[2*pos+1] = min(lazy[pos], lazy[2*pos+1]);
                lazy[2*pos+2] = min(lazy[pos], lazy[2*pos+2]);
            }
            lazy[pos] = INT_MAX;
        }
        
        // no overlap condition
        if (qlow > high || qhigh < low) {
            return INT_MAX;
        }
        //total overlap conditoin
        if (qlow<= low && qhigh>=high) {
            return tree[pos];
        }
        
        // partial overlap condition
        int mid = (low+high)>>1;
        return min(queryLazy(qlow,qhigh,low,mid,2*pos+1), queryLazy(qlow,qhigh,mid+1,high,2*pos+2));
    }

};