class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size(), res;
        //Space optimized solution as we only need dp[i] and dp[i-1]
        int prev, curr;
        //Covering the Base case
        prev = nums[0];
        res = prev;
        
        for(int i=1; i<n; i++){
            curr = max(nums[i], prev+nums[i]);
            res = max(res, curr);
            //Updating
            prev = curr;
        }
        return res;
    }
};