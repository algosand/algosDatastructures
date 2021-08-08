#include <bits/stdc++.h>
using namespace std;
const int NEUTRAL = 0;
/*
Segment tree for finding range sums in 1D array
Note for future, segment tree can be used for more than just what is thought.

It can be used as a decision tree to find say the number of empty spots in front of an item. 
and you can mark 0 as empty and 1 as not empty.  then you can binary search if you need 4 empty spots in front of a person
for that number.  
*/
struct SegTree {
    int size;
    vector<int> tree;
    void init(int n) {
        size = 1;
        while (size<n) {
            size*=2;
        }
        tree.assign(2*size,NEUTRAL);
    }
    void update(int i, int v, int x, int lx, int rx) {
        if (rx-lx==1) {
            tree[x]=v; // value at leaf node
            return;
        }
        int m = lx+rx>>1;
        if (i<m) {
            update(i, v, 2*x+1,lx,m);
        } else {
            update(i,v,2*x+2,m,rx);
        }
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }
    // [l,r) query, note it is exclusive of r
    int query(int l, int r, int x, int lx, int rx) {
        if (lx>=r || l>=rx) {
            return NEUTRAL;
        }
        if (lx>=l && rx<=r) {
            return tree[x];
        }
        int m = lx+rx>>1;
        int sl = query(l,r,2*x+1,lx,m);
        int sr = query(l,r,2*x+2,m,rx);
        return sl+sr;
    }

    int query(int l, int r) {
        return query(l,r,0,0,size);
    }
};


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

/*
Segment tree for finding maximum over a range when 
*/

const int NEUTRAL = 0;
struct SegTree {
    int size;
    vector<int> tree;
    void init(int n) {
        size = 1;
        while (size<n) {
            size*=2;
        }
        tree.assign(2*size,NEUTRAL);
    }
    void update(int i, int v, int x, int lx, int rx) {
        if (rx-lx==1) {
            tree[x]=v; // value at leaf node
            return;
        }
        int m = lx+rx>>1;
        if (i<m) {
            update(i, v, 2*x+1,lx,m);
        } else {
            update(i,v,2*x+2,m,rx);
        }
        tree[x]=max(tree[2*x+1],tree[2*x+2]);
    }
    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }
    // [l,r) query, note it is exclusive of r
    int query(int l, int r, int x, int lx, int rx) {
        if (lx>=r || l>=rx) {
            return NEUTRAL;
        }
        if (lx>=l && rx<=r) {
            return tree[x];
        }
        int m = lx+rx>>1;
        int sl = query(l,r,2*x+1,lx,m);
        int sr = query(l,r,2*x+2,m,rx);
        return max(sl,sr);
    }

    int query(int l, int r) {
        return query(l,r,0,0,size);
    }
};
