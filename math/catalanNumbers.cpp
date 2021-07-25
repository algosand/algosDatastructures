#include <bits/stdc++.h>
using namespace std;
/*
This code includes the O(n) solution and it also has the inverse from modInverse.cpp if you 
need to take the modulus because you are computing a really large catalan number such as 25000th 
catalan number.  
*/
long long binomialCoefficient(int n, int k) {
    int mod = 1e9+7;
    if (k>n-k) {
        k = n-k;
    }
    long long res = 1;
    for (int i = 0;i<k;i++) {
        res = (res*(n-i))%mod;
        res = (res*inverse(i+1,mod))%mod;
    }
    return res;
}

int catalan(int n) {
    long long c = binomialCoefficient(2*n,n);
    return (c*inverse(n+1,mod))%mod;
}

/*
Brute force dynamic programming solution that is done in O(n^2) time. 
*/
int catalanbrute(int n) {
    vector<int> catalan(n+1,0);
    catalan[0]=catalan[1]=1;
    for (int i = 2;i<=n;i++) {
        for (int j = 0;j<i;j++) {
            catalan[i]+=catalan[j]*catalan[i-j-1];
        }
    }
    return catalan[n];
}

int main() {

}