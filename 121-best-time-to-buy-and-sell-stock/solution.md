# Intuition
To maximize profit, you want to **buy at the lowest price** and **sell at the highest price** **after** that. So, as we iterate, we keep track of the **minimum price so far** and compute potential profits.

# Approach
- Initialize `minprice` with the first day's price.
- Initialize `maxprofit` as `0`.
- Traverse the array starting from index `1`:
  - If the current price is **less than `minprice`**, update `minprice`.
  - Otherwise, calculate the **profit** by subtracting `minprice` from the current price.
    - If this profit is greater than `maxprofit`, update `maxprofit`.

Return `maxprofit` at the end.

# Complexity
### Time complexity:
- **O(n)**: Traverse the array only once.

### Space complexity:
- **O(1)**: Only a few variables used.

# Code
```c []
int maxProfit(int* prices, int pricesSize) {
    
    int minprice = prices[0];
    int maxprofit = 0;
    for (int i = 1; i<pricesSize; i++)
    {
    if(prices[i]<minprice){
      minprice  = prices[i];
    }
    else{
      int profit  = prices[i]-minprice;
      if (profit>maxprofit)
      maxprofit = profit;
    }

}
return maxprofit;
}
```
