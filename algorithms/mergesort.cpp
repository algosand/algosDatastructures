#include <bits/stdc++.h>
using namespace std;
/*
The classic mergesort algorithm for sorting in nlogn time.  It uses recursion 
p,q,r are three pointers to define the boundaries of two adjacent subarrays.
p is leftmost index, q is the rightmost index for the left subarray.
q+1 is th eleftmost index, and r the rightmost index for the righ tsubarray.
left subarray bounds are [p,q]
right subarray bounds are [q+1,r]
Merge these two subarrays together, do that for all subarrays are in increasing order.
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

/*
A cool use of merge sort is to count the number of inversions for example take
[1,9,6,4,5], there are 5 inversions, that is the i<j and A[i]>A[j].

We can count the inversions during the merge sort process by counting the number of elements in the left
subarray that are smaller than elements in right subarray so for example

left subarray = [1,9], right subarray = [4,5,6]
we have 3 inversions because 9 is greater than 4,5,and 6.

what if we had 
left subarray = [1,6,9], right subarray = [4,5,7,8]
i is pointer to left subarray, and j to the right subarray
i = 1, and j = 0, at this point we have that A[i]>A[j], 
so we know that there are how many inversions with the 4 in the right subarray, since the left
subarray is sorted and it has length = 3, we know there are 3-1 = 2 inversions with the element 4 in the left subarray
So in total at each step we have

number of inversions = 2 + 2 + 1 + 1 = 6 

Below is an example problem where you can use counting inversions with merge sort to solve in (nlogn) time
This is to count the number of substrings that have more 1s than 0s.  
We use a prefix sum to derive this, the best way to understand is to draw out an example for 
110011 that should have answer 11.  
*/

long long ans;
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
        if (L[i]>R[j]) {
            ans += (nleft-i);
            nums[k]=R[j];
            j++;
        } else {
            nums[k] = L[i];
            i++;
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
long long countSubstring(string S){
    int n = S.size();
    vector<int> psum(n+1,0);
    for (int i = 0;i<n;i++) {
        psum[i+1] = psum[i]+ (S[i]=='0' ? 1 : -1);
    }
    ans = 0;
    mergeSort(psum, 0, n);
    return ans;
}