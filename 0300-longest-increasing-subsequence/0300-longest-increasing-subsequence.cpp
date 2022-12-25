class Solution {
public:
    // TC : O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), i, j, res = 1;
        
        //Creating a DP vector and initializing all to 1 bcz the minimum length can be 1
        vector<int> dp(n, 1);
        
        for(i=1; i<n; i++){
            for(j=i-1; j>=0; j--){
                //Comparing all the cases for the below condition
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};