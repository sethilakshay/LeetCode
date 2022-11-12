class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), i, j, res = 1;
        vector<int> dp(n, 1);
        
        for(i = 1; i<n; i++){
            
            for(j = i; j>=0; j--){
                
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], 1+dp[j]);
                
                res = max(dp[i], res);
            }
        }
        return res;
    }
};