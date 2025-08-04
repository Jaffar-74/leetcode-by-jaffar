# Intuition
If a number appears more than once in the array, sorting the array will place duplicates next to each other.
So, checking adjacent elements after sorting can efficiently detect any duplicate.


# Approach
- Sort the input array using `qsort()`.
- Scan the sorted array linearly and check if any two adjacent elements are equal.
- If a duplicate is found, return true; otherwise, return false.



# Complexity
- **Time complexity:** 
-`O(n log n)` Sorting takes O(n log n) time. Scanning for duplicates takes `O(n)` time. Total: `O(n log n)`.

- **Space complexity:** No extra space is used beyond the input array (assuming in-place sort). `qsort()` uses constant auxiliary space.

# Code
```c []
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);  // Sort the array

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}
```
