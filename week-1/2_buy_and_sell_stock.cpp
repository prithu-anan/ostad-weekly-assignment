/*
Time Complexity: O(n), due to looping through the entire array
Space Complexity: O(1), due to not using any additional space, but variables only
*/

int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int left = 0, right = 1;
  
    while(right < prices.size()){ // O(n) time
        if(prices[left] > prices[right]){
            left = right++;
            continue;
        }
        max_profit = max(max_profit, prices[right] - prices[left]);
        right++;
    }
    return max_profit;
}

/*
Explanation:
The code uses sliding window technique.
The left pointer stays stationary and the right pointer moves forward.
If the the left value is larger than the right one, then the left pointer is updated to the current right pointer.
This ensures that out of all the members explored in the array till now, the left pointer always points to the lowest value.
In each iteration, max profit is updated to current profit if current profit exceeds it.
After the end of the loop, we are guranteed to get the maximum profit.
*/
