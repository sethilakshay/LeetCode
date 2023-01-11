class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Length of longest increasing array
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            
            if(res.empty() || res.back() < nums[i]){
                res.push_back(nums[i]);
            }
            else{
                int lo = 0, hi = res.size()-1, mid;
                
                while(lo < hi){
                    mid = lo + (hi-lo)/2;
                    
                    if(res[mid] >= nums[i]){
                        hi = mid;
                    }
                    else{
                        lo = mid+1;
                    }
                }
                res[lo] = nums[i];
            }
        }
        return res.size();
    }
};