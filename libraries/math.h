#include <bits/stdc++.h>
using namespace std;
// for negative taking modulo
int modulo(int x, int y) {
    return (x%y+y)%y;
}
/*
Computes the euclidean distance squared, so like dist^2.  
*/
int euclideanDistance(pair<double, double>& c1, pair<double, double>& c2) {
    return (c1.first-c2.first)*(c1.first-c2.first)+(c1.second-c2.second)*(c1.second-c2.second);
}

// find the least common multiple of two integers a and b. 
long long lcm(long long a, long long b) {
    return b/gcd(a,b)*a;
}