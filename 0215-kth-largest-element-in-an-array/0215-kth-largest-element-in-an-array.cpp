class Solution {
public:
    int QuickSelect(int l, int r, vector<int>& nums, int idx){
        int start = l, pivot = nums[r];
        
        for(int i=start; i<r; i++){
            
            if(nums[i] <= pivot){
                
                swap(nums[i], nums[start]);
                start++;
            }
        }
        
        swap(nums[r], nums[start]);
        
        if(start > idx)
            return QuickSelect(l, start-1, nums, idx);
        
        else if(start < idx)
            return QuickSelect(start+1, r, nums, idx);
        
        else
            return nums[start];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        return QuickSelect(0, nums.size()-1, nums, nums.size()-k);
    }
};