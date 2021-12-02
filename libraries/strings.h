#include <bits/stdc++.h>
using namespace std;

/*
Function to check if it is palindrome, it uses a neat trick with the fact that
signed integers are represented as two's complement, so when you take the ~i, it return (-i-1)
that is ~i = (-i-1)

*/
bool isPalindrome(long long n) {
    string s = to_string(n);
    for (int i = 0;i<s.size()/2;i++) {
        if (s[i] != s.end()[~i]) {
            return false;
        }
    }
    return true;
}

/*
This is a hyper optimized version of the above function, it removes the construction of a string every time the 
function is called and instead can use a static array, that means it is constructed only once and remains available throughout the program

*/
bool isPalindrome(long long dec) {
    static int arr[64];
    int n = -1;
    while (dec>0) {
        arr[++n] = dec%10;
        dec/=10;
    }
    for (int i = 0;i<n;i++) {
        if (arr[i]!=arr[n--]) {
            return false;
        }
    }
    return true;
}