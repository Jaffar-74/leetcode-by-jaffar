# Intuition
In a **sorted array**, duplicate elements will always appear next to each other. So we can use two pointers to remove duplicates in-place by overwriting them as we go.

# Approach
Use two pointers: `i` for the **position of the last unique element**, and `j` to **iterate** through the array.
- Start from index 1 and compare `nums[j]` with `nums[i]`:
- If they are different, increment `i` and update `nums[i] = nums[j]`.
- After the loop, the first `i + 1` elements in `nums[]` will be the unique elements.<br>
The function returns `i + 1`, which is the **new length** of the array with unique elements.

# Complexity
### Time complexity:
- **O(n)**: Traverse the array once.

### Space complexity:
- **O(1)**: No extra space used; in-place modification.

# Code
```c []
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 0; 
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;              
            nums[i] = nums[j]; 
        }
    }
    return i + 1;
}

```
