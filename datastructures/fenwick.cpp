#include "../libraries/lib.h"

struct Fenwick {
    vector<int> bit;
    int size;
    void init(int n) {
        size = n;
        bit.resize(n);
    }
    void update(int idx, int delta) {
        while (idx < size) {
            bit[idx]+=delta;
            idx = idx | (idx + 1);
        }
    }
    int sum(int r) {
        int ret = 0;
        while (r>=0) {
            ret += bit[r];
            r = (r&(r+1))-1;
        }
        return ret;
    }
    int rsum(int l, int r) { // inclusive so [l,r]
        return sum(r)-sum(l-1);
    }
};