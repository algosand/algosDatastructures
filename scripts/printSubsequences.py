'''
This script is useful in visualizing all the subsequences that can be made from an array. 
And then it also stores the frequency of how many times a specific element appears as the minimum and maximum
in a subarray, this works for integers.  That is what it was used for initially. 
'''

from collections import Counter
freqMin = Counter()
freqMax = Counter()
def printSubsequences(arr, index, subarr):
       
    # Print the subsequence when reach 
    # the leaf of recursion tree

    if index == len(arr):
           
        # Condition to avoid printing
        # empty subsequence
        if len(subarr) != 0:
            if len(subarr)>1:
                freqMin[min(subarr)]+=1
                freqMax[max(subarr)]+=1
            print(subarr)
       
    else:
        # Subsequence without including 
        # the element at current index
        printSubsequences(arr, index + 1, subarr)
           
        # Subsequence including the element
        # at current index
        printSubsequences(arr, index + 1, 
                            subarr+[arr[index]])

def num(arr):

       
    return
if __name__ == '__main__':

    arr = [3,6,8,10,12]

    printSubsequences(arr, 0, [])
    print("max frequencies", freqMax)
    print("min frequencies", freqMin)
