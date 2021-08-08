#include <bits/stdc++.h>
using namespace std;
/*
This algorithm finds the longest lengthed palindrome in a string.  
This algorithm is meant to expand from each index in the string and 
find the length of the palindrome from that index. 
*/

int longestPallindrome(string& s) {
    int n = s.size();
    auto expand = [&](int i, int j) {
        while (i>=0 && j-i<n && j < n && s[i]==s[j]) {
            i--;
            j++;
        }
        return j-i-1;
    };
    int ans = 0;
    for (int i = 0;i<n;i++) {
        ans = max({ans, expand(i,i), expand(i,i+1)});
    }
    return ans;
}
    
int main() {

}