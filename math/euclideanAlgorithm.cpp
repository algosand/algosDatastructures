#include <bits/stdc++.h>
using namespace std;
/*
Euclidean Algorithm is the most efficient method to compute gcd or greatest common denominator.
Also you can use __gcd from C++ that is also efficient,
*/

// Euclidean algorithm to compute greatest common denominator
template <class T>
T gcd(T a, T b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main() {

}