#include <bits/stdc++.h>
using namespace std;
// compute prime numbers up to N, which can be up to 1e7 if I use long long
const long long N = 1e5;
// O(nlog(logn))
void primeSieve(vector<bool> &primes)
{
    primes[2] = true;
    for (long long i = 3; i < N; i += 2)
    {
        primes[i] = true;
    }
    for (long long i = 3; i < N; i += 2)
    {
        if (primes[i])
        {
            for (long long j = i * i; j < N; j += i)
            {
                primes[j] = false;
            }
        }
    }
}
/*
This uses the prime sieve algorithm in order to find the smallest prime factor for every integer up to and 
including n. 

*/
vector<int> spf;
void sieve(int n) {
    spf.resize(n+1); // smallest prime factor
    iota(spf.begin(),spf.end(),0);
    for (int i = 2;i*i<=n;i++) {
        if (spf[i]!=i) {continue;} // if the current number is not prime. 
        for (int j = i*i;j<=n;j+=i) {
            if (spf[j]==j) {
                spf[j]=i;
            }
        }
    }
}
/*
This is an example of an algorithm to get all the factors and return an unordered set of them. 
*/
unordered_set<int> getFactors(int n) {
    unordered_set<int> factors;
    while (n>1) {
        factors.insert(spf[n]);
        n/=spf[n];}
    return factors;
}
int main()
{
    /*
    This is getting the number of prime factors up to N.
    */
    auto start = chrono::high_resolution_clock::now();
    vector<bool> primes(N);
    primeSieve(primes);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << duration.count() << endl;
    int count = 0;
    for (long long i = 2; i < N; i++)
    {
        count += primes[i];
    }
    printf("count=%d\n", count);
    /*
    This code gets the factors for an integer.
    */
    // sieve(100000);
    // unordered_set<int> factors = getFactors(88000);
    // for (auto x : factors) {
    //     cout << x << endl;
    // }

}
