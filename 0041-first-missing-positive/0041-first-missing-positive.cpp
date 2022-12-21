class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size(), i = 0, j = n-1;
        
        // To find the valid range and put the rest of the elements in the end
        while(i <= j){
            if(nums[i] >= 1 && nums[i] <= n){
                i++;
            }
            else{
                swap(nums[i], nums[j]);
                j--;
            }
        }
        
        int valIdx = i;
        for(i = 0; i < valIdx; i++){
            
            if(nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        for(i = 0; i < valIdx; i++){
            
            if(nums[i] > 0){
                return i+1;
            }
        }
        
        return valIdx+1;
    }
};