class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        // Sort the input array to get it in order
        sort(nums.begin(), nums.end());
        int n = nums.size(), lo, hi = n-1, mid, mod = 1e9+7, res = 0;
        
        vector<int> dp(n, 1);
        
        // For each i from 0 to n-1, find the max j such that nums[i] + nums[j] <= target
        
        for(int i=0; i<nums.size(); i++){
            
            lo = i;
            
            while(lo < hi){
                mid = lo + (hi - lo + 1)/2;
                
                if(nums[i] + nums[mid] <= target){
                    lo = mid;
                }
                else{
                    hi = mid-1;
                }
            }
            
            // Sanity check to ensure if we have found an element or not
            if(nums[hi] + nums[i] > target){
                continue;
            }
            int power = hi-i;
            long long prev = 1, curr = 1;
            while(power > 30){
                curr = (((int) pow(2, 30) % mod) * (prev % mod)) % mod;
                curr %= mod;
                prev = curr;
                power -= 30;
            }
            res += ((curr%mod) * ((long long) pow(2, power)%mod)) % mod;
            res %= mod;
        }
        return res;
    }
};