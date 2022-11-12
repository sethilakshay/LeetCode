class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        
        int res = 0, cum_sum = 0, rem;
    
        hash_map[0] = 1;
        for(int i=0; i<nums.size(); i++){
            
            cum_sum += nums[i];
            
            rem = cum_sum%k;
            if(rem<0)
                rem += k;
            
            if(hash_map.find(rem) != hash_map.end())
                res += hash_map[rem];
            
            hash_map[rem]++;
        }
        return res;
    }
};