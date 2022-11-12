class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        int res = 0, run_sum = 0;
        
        hash_map[0] = 1;
        for(int i = 0; i<nums.size(); i++){
            run_sum += nums[i];
            
            if(hash_map.find(run_sum-k) != hash_map.end()){
                res += hash_map[run_sum-k];
            }
            
            hash_map[run_sum]++;
        }
        return res;
    }
};