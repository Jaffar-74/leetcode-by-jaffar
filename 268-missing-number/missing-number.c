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