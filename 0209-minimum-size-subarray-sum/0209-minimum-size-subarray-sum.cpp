class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int res = INT_MAX, currSum = 0;
        int i = 0, j = 0;
        
        while(j<nums.size() && i<=j){
            while(currSum < target && j<nums.size()){
                currSum += nums[j];
                j++;
            }
            
            while(currSum >= target){
                res = min(res, j-i);
                currSum -= nums[i];
                i++;
            }
        }
        return res == INT_MAX ? 0 : res;   
    }
};