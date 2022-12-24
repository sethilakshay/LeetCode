class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size(), res;
        vector<int> dp(n, 1);
        
        for(int i=0; i<n; i++){
            
            for(int j=i; j>=0; j--){
                
                if(nums[j] < nums[i]){
                    dp[i] = max(1+dp[j], dp[i]);
                }
                res = max(dp[i], res);
            }
        }
        return res;
    }
};