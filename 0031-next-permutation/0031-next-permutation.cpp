class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i, n = nums.size(), j;
        
        for(i = n-2; i>=0; i--){
            
            if(!(nums[i] >= nums[i+1]))
                break;
        }
        
        if(i<0){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(j=n-1; j>i; j--){
            
            if(nums[j] > nums[i]){
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                break;
            }
        }
        return;
    }
};