class Solution {
public:
    //TC: O(N logN)
    int lengthOfLIS(vector<int>& nums) {

        vector<int> vect;
        vect.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++){
        
            if(vect.back() < nums[i])
                vect.push_back(nums[i]);
            
            else if (vect.back() > nums[i]){
                //Task is to find the element in arr just bigger or equal to nums[i]
                int lo = 0, hi = vect.size()-1, mid;
                
                while(lo<hi){
                    
                    mid = lo + (hi-lo)/2;
                    //Predicate: Update lo if nums[i]>nums[mid]
                    //FFFFF*TTTTT*: Find the first True according to the above Predicate
                    
                    if(nums[i] > vect[mid])
                        lo = mid+1;
                    
                    else
                        hi = mid;
                }
                //Sanity check and updating only if needed
                if(vect[hi]>nums[i])
                    vect[hi] = nums[i];
            }
        }
        return vect.size();
    }
};