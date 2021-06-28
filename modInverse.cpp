#include <bits/stdc++.h>
using namespace std;
/*
multiplicative inverse modulus computation by algorithms.
 mod inverse in python is just pow(2,-1,mod) 
1) Euler's theorem
*/

// binary exponentiation
int mod = 1e9+7;
int power(long long a, int b) {
    long long result = 1;
    while (b>0) {
        if (b%2 == 1) {
            result = (result*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }
    return result;
}

// euler's theorem
int inverse(int a, int b) {
    return power(a, b-2);
}

int main() {
    int x;
    cin>>x;
    cout<<inverse(x,mod)<<endl;
}