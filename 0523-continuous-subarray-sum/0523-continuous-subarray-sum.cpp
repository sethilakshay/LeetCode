class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Hash Map to store the remainders and indices
        unordered_map<int, int> hash_map;
        // When empty array, rem is zero and possible index = -1
        hash_map[0] = -1;
        
        long cum_sum = 0, n = nums.size(), rem = 0;
        
        for(int i=0; i<n; i++){
            
            cum_sum += nums[i];
            rem = cum_sum%k;
            
            if(rem < 0){
                rem += k;
            }
            
            if(hash_map.find(rem) != hash_map.end()){
                if(i - hash_map[rem] >= 2){
                    return true;
                }
            }
            else{
                hash_map[rem] = i;
            }
        }
        return false;
    }
};