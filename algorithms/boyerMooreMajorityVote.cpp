#include <bits/stdc++.h>
using namespace std;
/*
Boyer-Moore Majority Vote Algorithm for finding the majority elements that appear more than one-third of 
of the elements in a sequence.  Normally it is for finding the majority element that appears more than 
half of the number of elements in sequence.  But it is the same thing just the other one is simpler then this
with just keeping track of one pointer. 
*/
vector<int> majorityVote(vector<int>& nums) {
    int n = nums.size();
    int x, y, cx = 0, cy=0;
    for (int num : nums) {
        if (cx==0) {
            swap(num,x);
            cx++;
        } else if (num==x) {
            cx++;
        } else if (cy==0) {
            swap(num,y);
            cy++;
        } else if (num==y) {
            cy++;
        } else {
            cx--;
            cy--;
        }
    }
    vector<int> ans;
    cx = 0, cy = 0;
    for (int num : nums) {
        if (num==x) {
            cx++;
        } else if (num==y) {
            cy++;
        }
    }
    if (cx>n/3) {
        ans.push_back(x);
    }
    if (cy>n/3) {
        ans.push_back(y);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main() {

}