class Solution {
public:
    // TC: O(N^2)
    // Using Dynamic Programming
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, INT_MAX-1);
        
        // Since no jump is needed to reach index 0
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(j + nums[j] >= i){
                    dp[i] = min(dp[i], 1+dp[j]);
                }
            }
        }
        return dp[n-1];
    }
};