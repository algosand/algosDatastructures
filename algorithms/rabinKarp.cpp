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
    /*
    hashes = [c0p^0, c0p^0+c1p^1, c0p^0+c1p^1+c2p^2, ...]
    */
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
/*
A variant of rolling hash that is useful for binary searching and using rolling hash. such as find common substring amongst multiple strings
The main difference is how you are computing the rolling hash, I don't precompute it because we can't
just easily update the curHash and multiply it by the pows[i] to see if it equals. 
We need to store rolling hashes at each iteration of binary search, with varying lengths, best way
is to use this formula for updating curHash = (a0p^2+a1p^1+a2p^0 - a0p^2)*p+a4p^0
Basically we are adding the next term, and remove the earliest term which has the maximum power we know 
for the length of the characters.  and we need multiply by p to update it for the next polynomial hash. 
This way you can store all polynomial hashes for some substring length, 
Then I can iterate through all substring polynomial hashes of the next substring and see if it was already seen
in an efficient manner.  
*/

auto check = [&](const int len) {
    // Precompute the hashes
    unordered_set<int> seen;
    int curHash = 0;
    for (int i = 0;i < n;i++) {
        curHash = i<len ? (curHash + ((nums1[i]+1)*pows[len-i-1])%mod)%mod : (((curHash-((nums1[i-len]+1)*pows[len-1])%mod+mod)%mod)*pows[1])%mod + nums1[i]+1;
        if (i>=len-1) {
            seen.insert(curHash);
        }
    }
    curHash = 0;
    for (int i = 0;i < m;i++) {
        curHash = i<len ? (curHash + ((nums2[i]+1)*pows[len-i-1])%mod)%mod : (((curHash-((nums2[i-len]+1)*pows[len-1])%mod+mod)%mod)*pows[1])%mod + nums2[i]+1;
        if (i>=len-1 && seen.count(curHash)>0) {
            return true;
        }
    }
    return false;
};


/*
Couple of ways to generate the polynomial hash equations
hashes = [c0p^0, c0p^0+c1p^1, c0p^0+c1p^1+c2p^2, ...]

if you take hashes[lhs]-hashes[rhs] = c1p^1+c2p^2 = hashes[3]-hashes[1], 
so to check if a string matches with that you need to make sure to multiple
any pattern hash by pows[1], cause if it only has two terms it may be 
c1p^0+c2p^1, which is equal but need to multiple by p. 
*/
vector<int> hashes(n+1, 0);
for (int i = 0;i < n;i++) {
    hashes[i+1] = (hashes[i] + ((s[i]-'a'+1)*pows[i]))%mod;
}

/*
hashes = [c0p^0, c0p^1+c1p^0, c0p^2+c1p^1+c2p^0,...]

If you take hashes[lhs]-hashes[rhs]*pows[rhs-lhs] = hashes[3]-hashes[1]*pows[3-1]=c0p^2+c1p^1+c2p^0 - c0p^2 = c1p^1+c2p^0
Which is the polynomial hash for that string, you can now compare this to another string to see if it matches
*/
vector<int> hashes(n+1,0);
for (int i=0;i<n;i++) {
    hashes[i+1]=(hashes[i]*pows[i]+(s[i]-'a'+1))%mod;
}
/*
a0p^0+a1p^1+a2p^2 for len=3 prefix
a0p^2 + a1p^1+a2^p2, which if it is aba and aba it works.  

These are two opposite ways to generate a polynomial hash function

one is to multiple all the previous by p
or to add on and multiple by higher powers of p. 
*/

/*
Polynomial hash for integers, let's say you have a series of integers that can be between the value of -1e5 to 1e5, that means 
you have 200,000 unique integers you need to hash, so I choose p = 200,003, the next prime number,
and I want to check that I have three unique integers via a polynomial hash.  
*/

const int MOD = 1e9+7;
const long long p = 2e5+3, offset = 1e5;
int getHash(long long x, long long y, long long z) {
    x+=offset;
    y+=offset;
    z+=offset;
    return ((x*p)%MOD + ((y*p)%MOD*p)%MOD + (((z*p)%MOD*p)%MOD*p)%MOD)%MOD;
}

/*
This is a rolling hash solution to a problem of finding the longest duplicate substring.  It is a very good example of using a rolling hash
algorithm. 

A variant of rolling hash that is useful for binary searching and using rolling hash. such as find common substring amongst multiple strings
The main difference is how you are computing the rolling hash, I don't precompute it because we can't
just easily update the curHash and multiply it by the pows[i] to see if it equals. 
We need to store rolling hashes at each iteration of binary search, with varying lengths, best way
is to use this formula for updating curHash = (a0p^2+a1p^1+a2p^0 - a0p^2)*p+a4p^0

Additional thoughts that are important is that there is a lot of substring combinations to try here.
There are 2^n, so with this there is a higher chance of collision with the rolling hash.  The reason behind this collision is because
there are two things you can say about a hash.  Suppose the hash = 22, now if this hash does exist in the map of seen hashes previously.  
That indicates that this string does not exist, has not been processed prior.  That means it is not a duplicate.  
Alternatively if the hash = 22 does exist in the map, that means the string could be a duplicate.  So to actually determine if it is a 
duplicate you need to iterate through all previous strings that produce a duplicate by storing the starting index. and find if it actually is
a duplicate.  

But this algorithm is still almost (maybe that is amortized) O(nlogn), because the hash is good, there isn't going to be too many collisions.  With a poor hash it would be worse case O(n^2logn)
*/
const long long p = 31;
const int MOD = 1e9+7;
string longestDupSubstring(string s) {
    int n = s.size();
    int lo = 0, hi = n-1;
    auto check = [&](const int len) {
        string res = "";
        if (len==0) {return res;}
        unordered_map<int, vector<int>> seen;
        int hash = 0;
        vector<long long> pows(len,1);
        for (int i = 1;i<len;i++) {
            pows[i] = (pows[i-1]*p)%MOD;
        }
        for (int i = 0;i<len;i++) {
            int coeff = s[i]-'a';
            hash = ((hash*p)%MOD+coeff)%MOD;
        }
        seen[hash].push_back(0);
        for (int i = len;i<n;i++) {
            int aprev = s[i-len]-'a', acur = s[i]-'a';
            hash = (hash - (aprev*pows.end()[-1])%MOD + MOD)%MOD;
            hash = ((hash*p)%MOD + acur)%MOD;
            if (seen.find(hash)!=seen.end()) {
                string cand = s.substr(i-len+1,len);
                for (auto &start : seen[hash]) {
                    if (strcmp(s.substr(start,len).data(), cand.data())==0) {
                        return cand;
                    }
                }
            }
            seen[hash].push_back(i-len+1);
        }
        return res;
    };
    while (lo<hi) {
        int mid = lo+hi+1>>1;
        string tmp = check(mid);
        if (!tmp.empty()) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    return check(lo);
}