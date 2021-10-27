

/*
[2,0,2,1,1,0]


[2,0,2,1,1,0]

[2,0,1]

[0,0,1,2,1,2,2]

This is an example of using pointers to solve a problem in-place, thus reducing space complexity.  This way you 
do not need to use memory in the program.  

The problem statement is the following, suppose you have 3 distinct elements could be 3 colors, red, white, and blue. 
You want to sort these 3 distinct elements, if we consider them as 0,1,2 it is easy.  We want to sort it, so [0,0,1,1,2,2] 
is sorted.  

Now it is very easy to solve this problem in O(nlogn) with using the in-built sort that comes with most computer languages
This usually uses some form of quick sort algorithm.  Or you could solve it with O(n) but use O(n) memory, but what if 
n is very large and you don't have enough memory in the compute to store the array's elements.  Then this wouldn't work.  
So the question is if you are limited by the memory, can you still solve it in O(n) time complexity, which may take a while
but that is fine, we have the time, and we can't do any better.  

So thinking about this problem, a possible solution is to consider using three pointers as seen below.  
Let's suppose we have left, i (moving pointer), and right.  The left and right will be quasi-fixed pointers, while the 
i pointer is scanning the array in O(n) time.  

Another interpretation is to be more general.  Let's say you are designing a sorting algorithm that is a variant of quicksort 
but needs to be adept for repeated elements.  So for example this problem we are going to use a three-way partitioning
that will group items that are less than 1, and equal to 1, and greater than 1.  But what would happen if instead of 
having 3 distinct elements that repeat in an array.  What if we have 5 distinct elements that repeat in an array? 
What if we have n distinct elements that repeat in an array? How can you efficiently solve this?  At what point
is n too large that the fact it has repeated elements, it no longer matters.  For instance if the array is like this 
[1,1,2,2,3,4,5,5,6,7], so like we have 7 repeating elements, but they first off only repeat at most 2 times, 
and the size of the array is only 10.  I mean not all elements are repeating here, is this just a normal quicksort
algorithm is best? 

The left pointer will always point to the first element in the array, or to the next element after that last 0.  
That is
example 1: The left pointer starts just pointing at the first element in the array.  
[1,0,2]
 ^
example 2: The left pointer is still pointing to first element in the array and it is pointing to 0. 
[0,1,2]
 ^  
 example 3: The left pointer is at the last 0, where it is all 0s before the pointer.
 [0,0,0,1,2,0,2]
        ^

The right pointer will point to the last element in the array, or to the last element before you have only 2s after it.
example 1:  Pointing to th elast element
[0,1,1]
     ^
example 2: Pointing to the front of the adjacent 2s. 
[0,1,0,1,2,1,2,2,2,2]
           ^
There are only two conditions when you would want to swap the moving pointer with the left or right pointer, and that 
is when left and right pointer will move. 
if moving pointer encounters a 0, push it to the front, where the left pointer is and move forward for both, because the
left pointer is guaranteed to be pointing to a 1.  The reason is that we have already processed all the values to the left.  

*/

void sortColors(vector<int>& nums) {
    int n = nums.size();
    for (int left = 0, i = 0, right = n-1;i<=right;) {
        if (nums[i]<1) {
            swap(nums[i], nums[left]);
            i++;
            left++;
        } else if (nums[i]>1) {
            swap(nums[i], nums[right]);
            right--;
        } else {
            i++;
        }
    }
}


