// Link to the problem - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(int* prices, int pricesSize){
    
    int max_profit = 0, min = 0, max = 0;
    
    // Iterate over the elements of the prices one by one
    for (int i = 0; i < pricesSize; ++i) {
        
        min = prices[i];
        // Compare the difference with the current max profit value and overwrite it if it is greater than the previous one
        for (int j = i + 1; j < pricesSize; ++j) {
            max_profit = (prices[j] - prices[i]) > max_profit ? (prices[j] - prices[i]) : max_profit;
        }
        
    }
    
    return max_profit;
}
