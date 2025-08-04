int coinChange(int* coins, int coinsSize, int amount) {
    int dp_arr[amount+1];

    for(int i =0; i<=amount; i++){
        dp_arr[i] = amount+1;
    }

    dp_arr[0] = 0;

    for(int i = 1;i<=amount; i++) {// outerloop will update the dp_arr (min coin needed)
        for(int j = 0 ; j<coinsSize; j++){
            if(i-coins[j]>=0){
               if (dp_arr[i] < dp_arr[i - coins[j]] + 1)
                  dp_arr[i] = dp_arr[i];
               else
                  dp_arr[i] = dp_arr[i - coins[j]] + 1; 
            }
        }
    }   

if (dp_arr[amount] > amount) {
    return -1;
} else {
    return dp_arr[amount];
}
}

/*
Function: coinChange
--------------------
This function calculates the **minimum number of coins** required to make up a given `amount`
using the denominations provided in the `coins[]` array. If the amount cannot be formed,
it returns -1.

Logical Flow:
-------------

1. Declare a dp array `dp_arr[]` of size `amount + 1`.
   - dp_arr[i] will store the minimum number of coins needed to make amount 'i'.

2. Initialize all entries of `dp_arr[]` to amount + 1 (considered as "infinity").
   - This represents an initially unreachable state.

3. Set `dp_arr[0] = 0` as the base case.
   - 0 coins are needed to make amount 0.

4. Loop from 1 to amount (outer loop `i`):
   - For each amount `i`, try all coin denominations (inner loop `j`).

5. If the current coin `coins[j]` can contribute to amount `i`:
   - i.e., if `i - coins[j] >= 0`
   - Then check:
     - If using this coin results in fewer coins: update `dp_arr[i]`
     - i.e., compare current dp_arr[i] with dp_arr[i - coins[j]] + 1

6. After filling the dp array:
   - If `dp_arr[amount]` is still greater than amount, return -1 (not possible)
   - Otherwise, return `dp_arr[amount]` (minimum coins needed)

Example:
--------
coins = {1, 2, 5}, amount = 11

dp_arr[11] would be filled with the minimum number of coins required to make 11.
For this example, the answer would be 3 (5 + 5 + 1)
*/