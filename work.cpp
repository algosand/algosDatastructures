#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& nums) {
    sort(nums.begin(),nums.end(),[&](const auto a, const auto b) {
        if (__builtin_popcount(a)!=__builtin_popcount(b)) {
            return __builtin_popcount(a)<__builtin_popcount(b);
        }
        for (int i = 31;i>=0;i--) {
            int bf = (b>>i)&1, af = (a>>i)&1;
            if (bf && !af) {
                return false;
            } else if (af && !bf) {
                return true;
            }
        }
        return true;});
    return nums;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    vector<int> arr;
    cin>>n;
    for (int i = 0;i<n;i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    solve(arr);
}