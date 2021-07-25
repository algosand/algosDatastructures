#include <bits/stdc++.h>
using namespace std;

/*
Learning about how dynamic programming can be used for digits. 
This is a topic I've avoided so far until it wrecked me again.  

*/


/*
Example 1:  sum of digits 
https://www.spoj.com/problems/CPCRC1C/

Example 2: digit sum
https://www.spoj.com/problems/PR003004/
Basically these are same problem but the second one most definitely needs dp because it contains more digits possible in a number.
*/
long long dp[17][2]; // Sum of digts, you can have at most 10 digits, and so on.  
long long count(int n, int edge, string& s) {
    if (edge==0) {
        return (long long)pow(10,n);
    }
    if (n==0) {
        return 1;
    }
    long long cnt = 0;
    int ub = edge ? (s[s.size()-n]-'0') : 9;
    for (int digit = 0;digit<=ub;digit++) {
        cnt += count(n-1,edge&(digit==ub), s);
    }
    return cnt;
}
long long compute(int n, int edge, string& s) {
   if (n==0) { // 0 digits remain
       return 0;
   }
   if (dp[n][edge]!=-1) {
       return dp[n][edge];
   }
   int ub = edge ? (s[s.size()-n]-'0') : 9;
   long long sum = 0;
   for (long long digit = 0;digit<=ub;digit++) {
       sum += digit*count(n-1, edge&(digit==ub), s);
       sum += compute(n-1,edge&(ub==digit), s);
   }
   return dp[n][edge]=sum;
}
// int main() {
//     int N;
//     long long a, b;
//     cin>>N;
//     while (N--) {
//         cin>>a>>b;
//         if (a>0) {
//             a--;
//         }
//         string A = to_string(a), B = to_string(b);
//         memset(dp, -1, sizeof(dp));
//         long long lower = compute(A.size(), 1, A);
//         memset(dp,-1,sizeof(dp));
//         long long upper = compute(B.size(), 1, B);
//         long long ans = upper-lower;
//         printf("%lld\n", ans);
//     }
// }

/*
Example 3: Magic Numbers
https://codeforces.com/contest/628/problem/D

This one is hard I haven't figured it out yet. 
*/

int main() {
    
}