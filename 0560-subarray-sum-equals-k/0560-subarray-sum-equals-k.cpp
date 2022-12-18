class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        int res = 0, cum_sum = 0;
        
        hash_map[0] = 1;    //Base Case where sum = 0 when no element of the array included
        for(int i = 0; i<nums.size(); i++){
            cum_sum += nums[i];
            
            if(hash_map.find(cum_sum-k) != hash_map.end()){
                res += hash_map[cum_sum-k];
            }
            
            hash_map[cum_sum]++;
        }
        return res;
    }
};