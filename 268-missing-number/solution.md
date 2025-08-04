# Intuition
Given n numbers from the range `[0, n]`, one number is missing.
After sorting the array, the value at index `i` should be `i` itself.
If `nums[i] != i`, then i is the missing number.

# Approach
**1.** Sort the input array using qsort().

**2.** Iterate through the array:

**3.** For index i, check if `nums[i] != i`.

**4.** If true, return i as the missing number.

**5.** If all values match their indices, return n (for example, last number is missing).

# Complexity
- Time complexity: `O(n log n)`
Due to sorting with `qsort`.

- Space complexity: `O(1)`
Sorting is in-place; no extra memory is used.

# Code
```c []
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    return(*(int*)a - *(int*)b);
    // plus -> a>b; equal-> no change; Minus-> a<b;
}
int missingNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0, j =0; i<numsSize; i++, j++){
        if(i!=nums[j]){
            return i;
        }
    }
return numsSize;
}

```
