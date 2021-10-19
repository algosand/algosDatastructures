#include "../libraries/lib.h"
/*
This fenwick tree is for finding range sums.  
It creates a tree with n nodes. 
And you can update the value of the nodes by providing a delta, and it will increment the value of that node
by that delta.  So we can update the range sums. 

A very cool use of this fenwick tree is as a decision tree, where you update every node to be 1, when everything 
is true.  But whenever you want to turn off a node. you can update(idx,-1), which will decrement it to 0, and
turn it off, so now any range sums returns the number of nodes that are still true.  
*/
class fenwick {
    public:
    vector<int> bit;
    int n;
    void init(int n) {
        this->n = n;
        bit.resize(n);
    }
    void update(int idx, int delta) {
        while (idx<n) {
            bit[idx]+=delta;
            idx = idx|(idx+1);
        }
    }

    int sum(int r) {
        int ret = 0;
        while (r>=0) {
            ret+=bit[r];
            r=(r&(r+1))-1;
        }
        return ret;
    }

    int rsum(int l, int r) {
        return sum(r)-sum(l-1);
    }
};
/*
Example implementation where you update it to 1 and then update to -1 when you no longer need to include this
in the range sum for finding the number of elements in the array that are greater than or equal 
*/
int n = tickets.size();
vector<int> res(n);
fenwick f;
f.init(n);
map<int, vector<int>> midx;
set<int> seen(tickets.begin(),tickets.end());
for (int i=0;i<n;i++) {
    midx[tickets[i]].push_back(i);
    f.update(i,1);
}
int processed= 0;
for (int ticketNum : seen) {
    for (int tidx : midx[ticketNum]) {
        int front = f.rsum(0,tidx)*ticketNum;
        int back = f.rsum(tidx+1,n-1)*(ticketNum-1);
        res[tidx]= processed+front+back;
        printf("processed=%d,front=%d,back=%d, res[tidx]=%d\n", processed, front, back, res[tidx]);
        processed+=ticketNum;
        f.update(tidx,-1);
    }
}
return res;