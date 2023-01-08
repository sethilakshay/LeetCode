class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        unordered_set<int> hash_set(nums.begin(), nums.end());
        
        return hash_set.size() - hash_set.count(0);
    }
};