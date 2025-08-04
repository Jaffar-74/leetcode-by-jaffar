# Intuition
In an array where every element appears twice except one, sorting will bring duplicates next to each other.
So the single element will be the one that doesn't match its neighbor.


# Approach
**1.** Sort the array using `qsort()`.

**2.** Iterate over the array in steps of 2:

**3.** If `nums[i] != nums[i+1]`, return `nums[i]`.

**4.** If all pairs match, return the last element.

# Complexity
- **Time complexity:** `O(n log n)` (due to sorting)

- **Space complexity:** `O(1)` (in-place sorting) 

# Code
```c []
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int singleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 1; i += 2) {
        if (nums[i] != nums[i + 1]) {
            return nums[i];
        }
    }

    // If all pairs matched, the single number is the last one
    return nums[numsSize - 1];
}


/* apply quicksort fuction 
and iterate over I and J to compare the consequtive elements if not same then return */
```
