#include <bits/stdc++.h>
using namespace std;
/*
polynomial rolling hash or rabin-karp algorithm.  
Used hashing to do O(1) comparisons between pattern and text. 
string matching algorithm
In general will need to compute the window size of the pat and generate hash for
all the substrings in the string to find if pat is in the text. 
*/
int mod = 1e9 + 7;
int getHash(const string& s, vector<long long>& pows) {
    int mod = 1e9 + 7, hashed = 0;
    long long p = 31;
    // O(m)
    for (int i = 0;i < s.size();i++) {
        hashed = (hashed + ((s[i]-'a'+1)*pows[i])%mod)%mod;
    }
    return hashed;
}

// General idea of rabinkarp with rolling hash
// polynomial equation c0*p^0+c1*p^1+c2*p^2+...ck-1*p^k-1, where k is length of max(n,m)
/*
You can find the number of times a pattern matches a string in O(n+m) TC
*/
vector<int> rabinKarp(const string& s, const string& pat) {
    int n = s.size(), m = pat.size();
    int p = 31;
    // precompute the powers
    vector<long long> pows(max(n,m),0);
    pows[0] = 1;
    for (int i = 1;i < pows.size();i++) {
        pows[i] = (pows[i-1]*p)%mod;
    }
    // precompute the hashes for the string
    vector<int> hashes(n+1, 0);
    for (int i = 0;i < n;i++) {
        hashes[i+1] = (hashes[i] + ((s[i]-'a'+1)*pows[i]))%mod;
    }
    // compute the pattern hash
    int patHash = getHash(pat, pows);
    vector<int> matches;
    // find the occurrences
    for (int i = 0;i < n - m + 1;i++) {
        int curHash = (hashes[i+n]-hashes[i] + mod)%mod; // because of modding it is not guaranteed that hashes[i+n]>hashes[i] => thus you need to mod this result
        if (curHash == (patHash*pows[i])%mod) {
            matches.push_back(i);
        }
    }
    return matches;
}
int main() {
    
}
