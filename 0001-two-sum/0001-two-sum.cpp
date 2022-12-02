class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> idx_map;
        
        for(int i=0; i<nums.size(); i++){
            idx_map[nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i++){
            
            if(idx_map.find(target - nums[i]) != idx_map.end() && i != idx_map[target - nums[i]]){
                return {i, idx_map[target - nums[i]]};
            }
        }
        
        return {-1, -1};
    }
};