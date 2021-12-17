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
    }));
}

/*
Trim character, I've used this for triming all left tab characters. 
Can do the same for right trim of character if necessary too.  
*/

static inline void ltrimChar(string& s, char& c) {
    s.erase(s.begin(), find_if(s.begin(),s.end(), [](unsigned char ch) {
        return !(ch==c);
    }));
}

    rtrim(s);
    ltrim(s);
}