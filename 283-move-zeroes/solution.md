# Intuition
We need to move all zeros to the end of the array while keeping the relative order of non-zero elements intact. This can be visualized as "bubbling" zeros to the right.

# Approach
Loop through the array `numsSize` times.
- In each pass, iterate from `0` to `numsSize - 2`.
- If `nums[j] == 0`, swap it with `nums[j+1]`.
- This effectively pushes the zeros toward the end in a bubble sort-like manner.

> ⚠️ While this works, it is inefficient for large arrays due to repeated unnecessary swaps.

# Complexity
### Time complexity:
- **O(n²)**: For each element, we may loop through the array again — nested loop.

### Space complexity:
- **O(1)**: In-place swapping, no extra space used.

# Code
```c []
int *moveZeroes(int* nums, int numsSize) {
    
    for(int i = 0; i<numsSize; i++){
        for(int j = 0; j<numsSize-1;j++){
            if(nums[j]==0){
                nums[j] = nums[j+1];
                nums[j+1] = 0;
            }
        }
    }
return nums;
}
```
