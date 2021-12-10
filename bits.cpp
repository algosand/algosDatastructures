

/*
bit tricks

x^(x&(x-1)) => returns the rightmost 1 in binary representation of x.
ex = (1010)_2^(1000)_2 = (0010)_2
x & (-x) => returns the rightmost 1 in binary representation of x.

This is a method to iterate through all possible states, 
and then j will look at all possible subsets of the current set.

for (int i = 1;i<(1<<n);i++) {
    for (int j = i;j>0;j=((j-1)&i)) {
        if (sum[j]>sessionTime) {continue;}
        dp[i]=min(dp[i],dp[i^j]+1);
    }
}

A trick to flip all the bits in a value like gamma is to use xor with all the 1s.  
if gamma = 10100, then epsilon = 01011, beause 10100 ^ 11111 = 01011.
epsilon = gamma ^ ((1<<n)-1)


*/

