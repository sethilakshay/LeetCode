class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size(), cum_sum = 0, res = INT_MIN;
        
        for(int i=0; i<n; i++){
            
            cum_sum += nums[i];
            res = max(res, cum_sum);
            
            if(cum_sum < 0)
                cum_sum = 0;
        }
        return res;
    }
};