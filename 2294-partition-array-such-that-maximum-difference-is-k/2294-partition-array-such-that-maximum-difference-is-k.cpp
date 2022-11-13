class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int start = nums[0], res = 1;
        for(int i= 1; i<nums.size(); i++){
            
            if(nums[i] - start <=k)
                continue;
            
            else{
                res++;
                start = nums[i];
            }
        }
        return res;
    }
};