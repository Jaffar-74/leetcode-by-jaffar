# Climbing Stairs Problem

## Intuition
This code calculates the number of ways to climb `n` stairs where you can take 1 or 2 steps at a time. It uses dynamic programming with two variables to iteratively compute the Fibonacci-like sequence, where each state depends on the previous two.

---

## Approach

**Dynamic Programming with Space Optimization**

- **Problem Insight**:  
  To reach the `n`-th stair, you can either come from the `(n-1)`-th stair (1 step) or the `(n-2)`-th stair (2 steps).  
  So,  
  `ways(n) = ways(n-1) + ways(n-2)` — similar to the Fibonacci sequence.

- **Optimization**:  
  Instead of storing all intermediate results in an array, the code uses two variables (`a` and `b`) to keep only the last two values, reducing space complexity from `O(n)` to `O(1)`.


## Complexity

- **Time Complexity**: O(n)
→ The loop runs from 2 to n, performing constant time operations. 
- **Space Complexity**: O(1)
→ Only a constant amount of space (a, b, c) is used, regardless of n

## Code

```cpp
int climbStairs(int n) {
    if (n == 0 || n == 1)
        return 1;

    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;  // DP: ways(n) = ways(n-1) + ways(n-2)
        a = b;
        b = c;
    }
    return b;
}
