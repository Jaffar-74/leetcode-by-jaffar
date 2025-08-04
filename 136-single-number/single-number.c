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