class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size(), goal = n-1;
        vector<int> dp(n);
        dp[0] = 0;
        
        for(int i = 1; i<n; i++){
            dp[i] = max(dp[i-1], nums[i-1])-1;
            
            if(dp[i] < 0)
                return false;
        }
        
        return dp[n-1] >= 0;
    }
};