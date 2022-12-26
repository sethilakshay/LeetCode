class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(), res;
        
        int curr_max, prev_max;
        int curr_min, prev_min;
        
        prev_max = nums[0];
        prev_min = nums[0];
        res = nums[0];
        
        for(int i=1; i<n; i++){
            
            curr_max = max(nums[i], max(nums[i]*prev_max, nums[i]*prev_min));
            curr_min = min(nums[i], min(nums[i]*prev_max, nums[i]*prev_min));
            
            res = max(res, curr_max);
            prev_max = curr_max;
            prev_min = curr_min;        
        }
        return res;
    }
};