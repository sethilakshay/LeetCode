class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= n1){
                n1 = nums[i];
            }
            else if(nums[i] <= n2){
                n2 = nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};