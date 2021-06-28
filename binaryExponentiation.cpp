#include <bits/stdc++.h>
using namespace std;
/*
Binary exponentiation. 
a^b, what is the computation 
*/
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

int main() {
    int x, y;
    cin>>x>>y;
    cout<<power(x,y)<<endl;;
}