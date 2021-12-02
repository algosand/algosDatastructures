#include <bits/stdc++.h>
using namespace std;

/*
General approach for converting to base 10 from a string of digits. 
Best way to understand is to draw it out. 
*/
long long toBase10(string& s, int base) {
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = res*base + (s[i]-'0');
    }
    return res;
}