class Solution {
public:
    int binSearch(int lo, int hi, vector<int>& nums, int& target){
        
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int lo = 0, hi = nums.size()-1, mid;
        
        //To check if array is rotated and if yes, place lo at the smallest position
        while(lo<hi){
            
            if(nums[lo] > nums[hi]){
                mid = lo + (hi-lo)/2;
                
                if((nums[lo]+nums[hi])/2 < nums[mid])
                    lo = mid+1;
                else
                    hi = mid;
            }
            else{
                break;
            }
        }
        
        if(target <= nums[nums.size()-1])
            return binSearch(lo, nums.size()-1, nums, target);
        else
            return binSearch(0, lo-1, nums, target);    
    }
};