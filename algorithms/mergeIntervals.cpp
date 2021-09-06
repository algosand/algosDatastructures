#include <bits/stdc++.h>
using namespace std;
/*
The classic merge intervals algorithm that comes in handy often. 
O(n) it uses a sliding window algorithm.  That just checks for overlap with the start and the previous end value.

*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    int prevEnd = -1;
    for (auto &interval : intervals) {
        int start = interval[0], end = interval[1];
        if (start>prevEnd) {
            merged.push_back({start,end});
        } else {
            merged.back()[1] = max(prevEnd, end);
        }
        prevEnd = merged.back()[1];
    }
    return merged;
}
int main() {

}