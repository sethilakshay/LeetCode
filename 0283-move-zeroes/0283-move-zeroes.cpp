class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int zero_ptr = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[zero_ptr], nums[i]);
                zero_ptr++;
            }
        }
    }
};