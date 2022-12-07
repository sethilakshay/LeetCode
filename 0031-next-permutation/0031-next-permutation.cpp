class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(), i = n-2, j = n-1;
        
        while(i>=0){
            if(nums[i] < nums[i+1]){
                break;
            }
            i--;
        }
        
        if(i == -1){
            return reverse(nums.begin(), nums.end());
        }
        
        while(nums[j] <= nums[i]){
            j--;
        }
        
        swap(nums[j], nums[i]);
        return reverse(nums.begin() + i+1, nums.end());
        
    }
};