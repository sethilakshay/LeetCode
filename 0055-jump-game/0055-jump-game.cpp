class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n  = nums.size(), target = n-1, curr = n-2;
        
        while(curr >= 0){
            
            if(curr + nums[curr] >= target){
                target = curr;
            }
            curr--;
        }
        return target == 0;
    }
};