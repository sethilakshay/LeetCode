class Solution {
public:
    void findSubsets(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& res){
        // Base Case
        if(idx == nums.size()){
            res.push_back(curr);
            return;
        }
        
        // Recursion
        // Include in res
        curr.push_back(nums[idx]);
        findSubsets(nums, idx+1, curr, res);
        curr.pop_back();
        
        // Exclude in res
        findSubsets(nums, idx+1, curr, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curr;
        vector<vector<int>> res;
        
        findSubsets(nums, 0, curr, res);
        return res;
    }
};