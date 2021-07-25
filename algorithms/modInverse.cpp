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

/*
Tutorial on how to use this in code.  

Let's say you are using a mod, 

if you need to compute a/b mod m
you can compute that by doing the following
(a*inverse(b,m))%m

This is the way to compute the modulus for division, you can just perform modulus on numerator
and denominator.  
*/