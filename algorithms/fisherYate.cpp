#include <bits/stdc++.h>
using namespace std;
/*
This is an efficient algorithm for random shuffling of an array

The basic idea is to shuffle by moving a pointer in the leftwards direction. 
And you swap random index as iterating through it.  Thus for index > i, it is all sorted in the array.

O(n) way to shuffle an array. 
*/
void fisherYates(vector<int>& nums) {
    srand(time(NULL));
    int n = nums.size();
    for (int i = n-1;i>=0;i--) {
        int pos = rand()%(i+1);
        swap(nums[i],nums[pos]);
    }
}