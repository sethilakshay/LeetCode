class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)
            return n;
        
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        dp[n-2] = 2;
        
        for(int i=n-3; i>=0 ; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
        
    }
};