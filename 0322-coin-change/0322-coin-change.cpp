class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), i, j;
        
        vector<int> dp (amount+1, INT_MAX-1);
        
        //When Amount=0, we need 0 coins
        dp[0] = 0;
        
        for(i=0; i<n; i++){
            
            for(j=1; j<=amount; j++){
                
                if(j-coins[i]>=0)
                    dp[j] = min(dp[j], 1+dp[j-coins[i]]);
            }
        }
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};