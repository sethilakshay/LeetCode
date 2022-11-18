class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size(), cumSum = 0, i = 0, j = 0, res = INT_MAX;
        
        while(j<n){
            
            cumSum += nums[j];
            
            while(cumSum >= target && i<=j){
                res = min(res, j-i+1);
                cumSum -= nums[i];
                i++;
            }
            j++;
        }
        return res == INT_MAX ? 0 : res;
    }
};