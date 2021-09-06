#include <bits/stdc++.h>
using namespace std;

bool subseq(string& s1, string& s2) {
    // check if s1 is a subsequence of s2
    int i=0;
    for (char &c : s2) {
        if (i<s1.size() && s1[i]==c) {
            i++;
        }
    }
    return i == s1.size();
};