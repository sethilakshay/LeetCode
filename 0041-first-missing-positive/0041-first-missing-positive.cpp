class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size(), i = 0, j = n-1;
        
        while(i <= j){
            if(1<= nums[i] && nums[i] <= n){
                i++;
            }
            else{
                swap(nums[j], nums[i]);
                j--;
            }
        }

        int valIdx = i;
        
        for(int i=0; i<valIdx; i++){
            
            if(nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1]  *= -1;
            }
        }
        
        for(int i=0; i<valIdx; i++){
            
            if(nums[i] > 0){
                return i+1; 
            }
        }
        
        return valIdx + 1;
    }
};