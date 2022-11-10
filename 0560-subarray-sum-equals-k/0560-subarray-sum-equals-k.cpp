class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        int i, n = nums.size(), cum_sum = 0, res = 0;
        
        hash_map[0] = 1;
        
        for(i=0; i<n; i++){
            
            cum_sum += nums[i];
            
            if(hash_map.find(cum_sum-k) != hash_map.end()){
                
                res += hash_map[cum_sum-k];
            }
            hash_map[cum_sum]++;
        }
        return res;
        
    }
};