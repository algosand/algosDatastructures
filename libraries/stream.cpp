#include <bits/stdc++.h>
using namespace std;

/*
This is an example of using an istringstream object to create a stream of strings from the string s, that is separated 
by space by default.  And then read in the strings from the stream one at a time into the string word.  
*/

bool areNumbersAscending(string s) {
    string word;
    istringstream ss(s);
    int prev = -1;
    while (ss >> word) {
        if (isdigit(word[0])) {
            int val = stoi(word);
            if (val<=prev) {return false;}
            swap(prev,val);
        }
    }
    return true;
}