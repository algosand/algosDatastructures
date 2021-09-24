#include <bits/stdc++.h>
using namespace std;
/*
Example of how to use bitset from C++ for computations on sets
bitsets are basically bits of a specific size at compile time. 
They are highly optimized,  so bitset<2> bs = 00, initialize all bits to 0
but when you set bits you can change it to bs = 01,  so this is similar to 
masks and so on.  It can be used for masks and as an efficient representation
of the elements used, as opposed to using an unordered_set to store elements used.
*/

int maxLength(vector<string>& arr) {
    vector<bitset<26>> vec = {bitset<26>()};
    int ans = 0;
    for (string &s : arr) {
        bitset<26> bs;
        for (char &c : s) {
            int offset = c-'a';
            // Checks if this specific string doesn't contain unique characters
            if (bs.test(offset)) {
                bs.reset(); // reset the bits
                break;
            }
            bs.set(offset); // set the bit 
        }
        // checking if the current bitset has no bits set which indicates it doesn't contain just unique characters
        if (!bs.any()) {
            continue;
        }
        int n = vec.size();
        // Iterate through and take current bitset to use the bit operator or with all other previous bitsets. 
        for (int i = 0;i<n;i++) {
            if ((vec[i]&bs).any()) {
                continue;
            }
            vec.push_back(vec[i]|bs);
            ans = max(ans, (int)vec.back().count());
        }
    }
    return ans;
}