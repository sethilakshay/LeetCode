class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0, prev, curr, n = nums.size();
        
        prev = nums[0];
        res = nums[0];
        
        for(int i=1; i<n; i++){
            
            curr = max(prev + nums[i], nums[i]);
            res = max(res, curr);
            
            prev = curr;
        }
        return res;
    }
};