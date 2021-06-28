#include <bits/stdc++.h>
using namespace std;
/*
The method to compute the factorial up to a billion. 


*/
int mod = 1e9+7;
long long factorial(int x) {
    long long res = 1;
    for (int i = 1;i<=x;i++) {
        res = (res*i)%mod;
    }
    return res;
}

int main() {
    int x;
    cin>>x;
    cout<<factorial(x)<<endl;

}