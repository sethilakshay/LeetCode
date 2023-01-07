class Solution {
public:
    int subarraysWithAtmostKDistinct(vector<int>& nums, int k){
        int i, j, n = nums.size(), cnt_dist = 0, res=0;
        vector<int> freq(n, 0);

        j=0;
        for(i=0; i<n; i++){
            while(j<n && cnt_dist<=k){
                
                if (freq[nums[j]-1]==0) 
                    cnt_dist++;
                
                freq[nums[j]-1]++;
                j++;
            }
            if (cnt_dist>k)
                    res += j-i-1;
            else
                res += j-i;
            
            freq[nums[i]-1]--;
            if (freq[nums[i]-1]==0)
                     cnt_dist--;  
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k-1);
        
    }
};