#include "../libraries/lib.h"

class fenwick
{
public:
    vector<int> bit;
    int n;
    fenwick(int n)
    {
        this->n = n;
        bit.resize(n);
    }
    void update(int idx, int delta)
    {
        while (idx < n)
        {
            bit[idx] += delta;
            idx = idx | (idx + 1);
        }
    }

    int sum(int r)
    {
        int ret = 0;
        while (r >= 0)
        {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }
    // This is inclusive range sum so it is [l,r], so just remember when calling it
    // if you have 0,n, but you want sum [0,n-1], you need to call rsum(0,n-1)
    int rsum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};