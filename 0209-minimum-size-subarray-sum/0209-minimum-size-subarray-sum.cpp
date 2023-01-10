class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int res = INT_MAX, currSum = 0;
        int i = 0, j = 0;
        
        while(j<nums.size()){
            currSum += nums[j];
        
            while(currSum >= target){
                res = min(res, j-i+1);
                currSum -= nums[i];
                i++;
            }
            
            j++;
        }
        return res == INT_MAX ? 0 : res;   
    }
};