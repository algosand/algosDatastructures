#include <bits/stdc++.h>
using namespace std;

/*
Trie can be used to efficiently search for matches efficiently in a dictionary or in xor with bits
*/


/*
The Trie datastructure for used with binary digits, Can be used for bit manipulation.
This one is specifically for xor bit manipulation acting on the bits. 
*/
const int MAXDIG = 18; // if you only have 18 bits at most. 
struct Node {
    int cnt = 0; // count of this node
    int children[2]; // the children, can only be 2
    void init() { // initially set the node to have no children, as signified by -1, 
        children[0]=children[1]=-1;
    }
};

struct Trie {
    vector<Node> trie;
    void init() {
        Node root;
        root.init();
        trie.push_back(root);
    }
    void add(int x) {
        int cur = 0; // the root of the trie is always the 0th element in the trie vector
        for (int i=MAXDIG;i>=0;i--) {
            int c = (x>>i)&1; // check if the ith bit is set to 1 or not.  returns a 0 or 1
            if (trie[cur].children[c]==-1) {
                trie[cur].children[c]=trie.size();
                Node root;
                root.init();
                trie.push_back(root);
            }
            cur=trie[cur].children[c]; // traveling down the trie tree, by going to the child node.
            trie[cur].cnt++; // increase the number of this node. 
        }
    }
    void remove(int x) {
        int cur = 0;
        for (int i = MAXDIG;i>=0;i--) {
            int c = (x>>i)&1;
            assert(trie[cur].children[c]!=-1);
            cur = trie[cur].children[c];
            trie[cur].cnt--;
        }
    }
    int search(int x) { // find the best xor in trie
        int cur = 0, res = 0;
        for (int i = MAXDIG;i>=0;i--) {
            int c = (x>>i)&1; // find the current bit 0 or 1.
            // You want the opposite bit to maximize an xor, if 
            // if c=1, we want to move to a 0, and then add a 1 at this position
            // if c=0, we want to move to a 1, and then add a 1 at this position
            if (trie[cur].children[c^1]!=-1 && trie[trie[cur].children[c^1]].cnt>0) {
                res+=(1<<i);
                cur = trie[cur].children[c^1];
            } else {
                cur=trie[cur].children[c];
            }
        }
        return res;
    }
};