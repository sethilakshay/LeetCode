class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        
        // When no element in the array is considered, we have 0 remainder and index = -1
        hash_map[0] = -1;
        
        int cum_sum = 0, rem = 0;
        
        for(int i=0; i<nums.size(); i++){
            
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