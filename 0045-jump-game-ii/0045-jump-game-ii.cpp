class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, INT_MAX-1);
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