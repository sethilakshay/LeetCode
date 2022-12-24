class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1, -1};
        }
        
        int end;
        int lo = 0, hi = nums.size()-1, mid;
        
        while(lo<hi){
            mid = lo + (hi-lo+1)/2;
            
            if(nums[mid] <= target){
                lo = mid;
            }
            else{
                hi = mid-1;
            }
        }
        
        if(nums[lo] != target){
            return {-1, -1};
        }
        end = lo;
        
        lo = 0, hi = nums.size()-1;
        
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            
            if(nums[mid] >= target){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        
        if(nums[hi] != target){
            return {-1, -1};
        }
        
        return {hi, end};
    }
};