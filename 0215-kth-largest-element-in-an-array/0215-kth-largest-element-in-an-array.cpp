class Solution {
public:
    int QuickSelect(int l, int r, vector<int>& nums, int k){
        int start = l, pivot = nums[r], n = nums.size();
        
        for(int i=start; i<r; i++){
            
            if(nums[i] < pivot){
                
                swap(nums[i], nums[start]);
                start++;
            }
        }
        
        swap(nums[r], nums[start]);
        
        if(start == n-k){
            return nums[start];
        }
        
        else if(start < n-k){
            return QuickSelect(start+1, r, nums, k);
        }
        
        else{
            return QuickSelect(l, start-1, nums, k);
        }
        
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSelect(0, nums.size()-1, nums, k);
        
    }
};