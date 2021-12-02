#include <bits/stdc++.h>
using namespace std;
/*
The classic merge intervals algorithm that comes in handy often. 
O(n) it uses a sliding window algorithm.  That just checks for overlap with the start and the previous end value.
*/
void setmax(int &a, int b) {
    a = max(a,b);
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    int n = intervals.size();
    for (int i = 0;i<n;i++) {
        int start = intervals[i][0], end = intervals[i][1];
        if (i==0 || start>merged.back()[1]) {
            merged.push_back({start,end});
        } else {
            setmax(merged.back()[1], end);
        }
    }
    return merged;
}
int main() {

}

