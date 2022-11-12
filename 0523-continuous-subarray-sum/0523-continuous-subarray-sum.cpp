class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        int res = 0, run_sum = 0, rem;
        
        hash_map[0] = -1;
        for(int i = 0; i<nums.size(); i++){
            run_sum += nums[i];
            
            rem = run_sum%k;
            if(rem<0)
                rem += rem+k;
            
            if(hash_map.find(rem) != hash_map.end()){
                if(i - hash_map[rem] >= 2)
                    return true;
            }else{
                hash_map[rem] = i;
            }
        }
        return false;
    }
};