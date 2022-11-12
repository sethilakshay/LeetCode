class Solution {
public:
    int bin_search(int lo, int hi, vector<int>& nums, int& target){
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int lo = 0, hi = nums.size()-1, mid;
        
        while(lo<hi){
            
            if(nums[lo] > nums[hi]){
                mid = lo + (hi-lo)/2;
                if(nums[mid] >= nums[lo]){
                    lo = mid+1;
                }
                else{
                    hi = mid;
                }
            }
            else{
                break;
            }
        }
        
        if(target <= nums[nums.size()-1]){
            return bin_search(lo, nums.size()-1, nums, target);
        }
        else{
            return bin_search(0, lo-1, nums, target);
        }
        return -1;
    }
};