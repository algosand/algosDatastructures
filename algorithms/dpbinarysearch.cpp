#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
/*
This stores the best profit for a every start time, and it iterate in reverse for the start times
working it's way to the lowest start time, and then you find the jobs
that have this start time, and find there end time, and see if you can 
increase the maximum profit for the current start time with that job. if the endtime
corresponds to an earlier best value for another start time, and use binary search to find it.  

So this is a dp with binary search example.  
*/
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    map<int,int> dp;
    unordered_map<int, vector<pair<int,int>>> jobs;
    int n = profit.size();
    for (int i = 0;i<n;i++) {
        dp[startTime[i]]=0;
        jobs[startTime[i]].emplace_back(endTime[i], profit[i]);
    }
    int ans = 0;
    for (auto it=dp.rbegin(); it!=dp.rend();it++) {
        for (auto &[end, profit] : jobs[it->first]) {
            auto jt = dp.lower_bound(end);
            ans = max(ans, (jt==dp.end() ? 0 : jt->second) + profit);
            it->second = ans;
        }
    }
    return ans;
}
int main() {

}