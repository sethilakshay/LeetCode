class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hash_map;
        
        for(int i=0; i<nums.size(); i++){
            hash_map[nums[i]] = i;
        }
            
        for(int i=0; i<nums.size(); i++){
            if(hash_map.find(target - nums[i]) != hash_map.end() && hash_map[target - nums[i]] != i){
                return {i, hash_map[target - nums[i]]};
            }
        }
        return {-1, -1};
    }
};