class Solution {
public:
    int binSearch(int lo, int hi, int target, vector<int>& nums){
        int mid;
        
        while(lo<=hi){
            mid  = lo + (hi-lo)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int lo = 0, hi = nums.size()-1, mid;
        int pivot;
        
        while(lo<hi){
            
            if(nums[lo] > nums[hi]){
                mid = lo + (hi-lo)/2;

                if(nums[mid] <= (nums[lo] + nums[hi])/2){
                    hi = mid;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                break;
            }
        }
        
        if(target >= nums[lo] && target <= nums[nums.size()-1]){
            return binSearch(lo, nums.size()-1, target, nums);
        }
        else{
            return binSearch(0, lo-1, target, nums);
        }
    }
};