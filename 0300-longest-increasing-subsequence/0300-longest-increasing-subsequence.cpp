class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), i, j, res = 1;
        vector<int> dp(n, 1);
        
        for(i = n-2; i>=0; i--){
            
            for(j = i; j<n; j++){
                
                if(nums[i] < nums[j])
                    dp[i] = max(dp[i], 1+dp[j]);
                
                res = max(dp[i], res);
            }
        }
        return res;
    }
};