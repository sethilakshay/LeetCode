class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(), i, j;

        vector<int> dp(amount+1, 0);
        //vector<int> curr(amount+1, 0);
        
        //There is only 1 way in which amount==0, when no coin is included
        dp[0] = 1;
        
        for(i=n-1; i>=0; i--){
            
            for(j=1; j<=amount; j++){
                
                //curr[j] = prev[j];
                
                if(j-coins[i] >= 0)
                    dp[j] += dp[j-coins[i]]; 
            }
        }
        return dp[amount];
    }
};