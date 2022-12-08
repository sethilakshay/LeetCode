class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        
        i = n-2;
        
        while(i >= 0){
            if(!(nums[i] >= nums[i+1])){
                break;
            }
            i--;
        }
        
        if(i == -1){
            return reverse(nums.begin(), nums.end());
        }
        
        j = n-1;
        
        while(j > i){
            if(nums[j] > nums[i]){
                break;
            }
            j--;
        }
        
        swap(nums[i], nums[j]);
        return reverse(nums.begin() + i + 1, nums.end());
    }
};