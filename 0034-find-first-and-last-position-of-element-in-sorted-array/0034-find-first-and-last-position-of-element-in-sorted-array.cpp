class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return {-1,-1};
        int lo=0, hi=nums.size()-1, mid;
        //Nums sorted in ascending order
        //FFFF*TTTT*
        //Last F: Last instance of the number
        while(lo<hi){
            mid=lo+(hi-lo+1)/2;
            if(nums[mid]<=target){
                lo=mid;
            }
            else{
                hi=mid-1;
            }
        }
        if (nums[lo]!=target) return {-1,-1};
        int Last = lo;
        //First T: First instance of the number
        lo=0, hi=nums.size()-1;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]>=target){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        int First = hi;
        return {First, Last};
    }
};