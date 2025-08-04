# Intuition
We need to find two indices in the array such that the sum of their values equals the given target.
A brute-force way is to check all possible pairs and return the first one that satisfies the condition.

# Approach
Use a nested loop to check every unique pair `(i, j)` where `i < j`.
If `nums[i] + nums[j] == target`, store the indices in a dynamically allocated array and return it.



# Complexity
- **Time complexity:** `O(n^2)`
Two nested loops lead to quadratic time in the worst case, where all pairs are checked.

- **Space complexity:** Aside from the returned array (which is constant-sized), no extra memory is used.

# Code
```c []
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL; // Not expected as per constraints
}
```
