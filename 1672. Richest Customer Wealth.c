// Link to the problem - https://leetcode.com/problems/richest-customer-wealth/

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    
    int maximum_wealth = 0;
    
    // Iterate over each account per time
    for (int i = 0; i < accountsSize; ++i) {
        
        // Current wealth of the current account to be compared with the maximum wealth
        int current_wealth = 0;
        
        // Iterate over each bank account of the current customer 
        for (int j = 0; j < *accountsColSize; ++j) {
            current_wealth += accounts[i][j];
        }
        
        // If the current is greater than max wealth, then it's current max, otherwise the max stays the same
        maximum_wealth = current_wealth > maximum_wealth ? current_wealth : maximum_wealth; 
        
    }
    
    return maximum_wealth;
}
