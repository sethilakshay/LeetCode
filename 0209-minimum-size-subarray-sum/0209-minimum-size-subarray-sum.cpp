class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size(), i = 0, j = 0;
        int cum_sum = 0, res = INT_MAX;
        
        while(j<n){
            cum_sum += nums[j];
            
            while(cum_sum >= target && i<=j){
                res = min(res, j-i+1);
                cum_sum -= nums[i];
                i++;
            }
            j++;
        }
        return res == INT_MAX ? 0 : res;
    }
};