#include <bits/stdc++.h>
using namespace std;
/*
The classic mergesort algorithm for sorting in nlogn time.  It uses recursion 
p,q,r are three pointers to define the boundaries of two adjacent subarrays.
p is leftmost index, q is the rightmost index for the left subarray.
q+1 is th eleftmost index, and r the rightmost index for the righ tsubarray.
left subarray bounds are [p,q]
right subarray bounds are [q+1,r]
Merge these two subarrays together, do that for all subarrays.
Firstly this decomposes the array to subarrays of length 1 and then merges them all together. 
*/
void merge(vector<int>& nums, int p, int q, int r) {
    int nleft = q-p+1, nright = r-q;
    vector<int> L(nleft), R(nright);
    for (int i = 0;i<nleft;i++) {
        L[i]=nums[p+i];
    }
    for (int i = 0;i<nright;i++) {
        R[i]=nums[q+i+1];
    }
    int i = 0, j = 0, k = p;
    for (;i<nleft && j<nright;k++) {
        if (L[i]<R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k]=R[j];
            j++;
        }
    }
    for (;i<nleft;i++, k++) {
        nums[k] = L[i];
    }
    for (;j<nright;j++, k++) {
        nums[k]=R[j];
    }
}
void mergeSort(vector<int>& nums, int lo, int hi) {
    if (lo<hi) {
        int mid = lo+hi>>1;
        mergeSort(nums,lo,mid);
        mergeSort(nums,mid+1,hi);
        merge(nums,lo,mid,hi);
    }
}