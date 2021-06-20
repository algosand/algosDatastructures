#include <bits/stdc++.h>
using namespace std;

/*
An excellent method to create an array of tokens from a string that is space separated
*/
vector<string> getTokenArray(string &s) {
    stringstream ss(s);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> tokens(begin,end);
    return tokens;
}  
