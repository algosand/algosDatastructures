#include <bits/stdc++.h>
using namespace std;

static inline void rtrim(string& s) {
    s.erase(find_if(s.rbegin(),s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
}

static inline void ltrim(string& s) {
    s.erase(s.begin(), find_if(s.begin(),s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }))
}

static inline void trim(string& s) {
    rtrim(s);
    ltrim(s);
}