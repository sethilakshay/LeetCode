class Solution {
public:
    int subarraysWithAtmostKDistinct(vector<int>& nums, int k){
        
        int i = 0, j = 0, n = nums.size();
        int res = 0, cnt_dist = 0;
        vector<int> freq(n, 0);
        
        while(i < n){
            while(j<n && cnt_dist <= k){
                
                if(freq[nums[j] - 1] == 0){
                    cnt_dist++;
                }
                
                freq[nums[j] - 1]++;
                j++;
            }
            
            if(cnt_dist > k){
                res += j-i-1;
            }
            else{
                res += j-i;
            }
            
            freq[nums[i]-1]--;
            if(freq[nums[i]-1] == 0){
                cnt_dist--;
            }
            i++;
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Classic 2 Pointers question
        // Approach: Rather than finding the exact k
        // Why not find the distinct subarrays with atmost K distinct
        // To get our answer, simply subtract the atmost k-1 distinct
        
        return subarraysWithAtmostKDistinct(nums, k) - subarraysWithAtmostKDistinct(nums, k-1);
    }
};