#include <bits/stdc++.h>
using namespace std;

/*
This document contains examples of using bitmask to solve algorithm and datastructure problems. 
Two considerations I generally make
1. If I need to iterate through all possible submasks, I need to make sure that the bitmask contains small number of bits.
(2^(number of bits) submasks, 2^10=1024 submasks)
2. If I am just using the bitmask for hashing, then just need to confirm will fit within 32 bits usually (maybe 64 bits)
3. 
*/


/*
With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).
Return an array answer, where answer[i] is the number of words in the given word list words that is valid with respect to the puzzle puzzles[i].

This is a good example because I am using both considerations to solve the problem. 
It was given that the puzzles[i].length=7, so I can iterate through all 2^7 submasks but it's actually 2^6, because
the first character is always to match.  This would require understanding the problem
And the hashmap because at most 26 bits, for 26 lowercase characters. 
*/
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    unordered_map<int,int> counts;
    for (string &s : words) {
        int mask = 0;
        for (char &c : s) {
            int offset = c - 'a';
            mask |= (1<<offset);
        }
        counts[mask]++;
    }
    vector<int> valids;
    for (string &s : puzzles) {
        int n = s.size(), numValids = 0;
        for (int i = 0;i<(1<<6);i++) {
            int submask = 1<<(s[0]-'a');
            for (int j = 0;j<6;j++) {
                if ((i>>j)&1) {
                    int offset = s[j+1]-'a';
                    submask |= (1<<offset);
                }
            }
            numValids += counts[submask];
        }
        valids.push_back(numValids);
    }
    return valids;
}