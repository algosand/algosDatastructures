#include <bits/stdc++.h>
using namespace std;
// compute prime numbers up to N, which can be up to 1e7 if I use long long
const long long N = 1e7;

void primeSieve(vector<long long> &primes)
{
    primes[2] = 1;
    for (long long i = 3; i < N; i += 2)
    {
        primes[i] = 1;
    }
    for (long long i = 3; i < N; i += 2)
    {
        if (primes[i] > 0)
        {
            for (long long j = i * i; j < N; j += i)
            {
                primes[j] = 0;
            }
        }
    }
}
int main()
{
    auto start = chrono::high_resolution_clock::now();
    vector<long long> primes(N, 0);
    primeSieve(primes);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << duration.count() << endl;
    // for (long long i = 0; i < N; i++)
    // {
    //     if (primes[i] > 0)
    //     {
    //         printf("%lld ", i);
    //     }
    // }
}