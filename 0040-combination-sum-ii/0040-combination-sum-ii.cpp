class Solution {
public:
    void findSum(int idx, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res){
        // Base Case
        if(target == 0){
            res.push_back(curr);
            return;
        }
        
        if(target < 0 || idx == candidates.size()){
            return;
        }
        
        // Recursive Case
        
        // Include idx in curr;
        curr.push_back(candidates[idx]);
        findSum(idx+1, candidates, target - candidates[idx], curr, res);
        curr.pop_back();
        
        // Exclude
        int i = idx;
        while(i<candidates.size() && candidates[i]==candidates[idx]){
            i++;
        }
        findSum(i, candidates, target, curr, res);
        
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> curr;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        
        findSum(0, candidates, target, curr, res);
        return res;
    }
};