class Solution {
public:
    void findSol(int idx, int target, vector<int>& curr, vector<vector<int>>& res, vector<int>& candidates){
        // Base Case 1
        if(target == 0){
            res.push_back(curr);
            return;
        }
        // Base Case 2
        if(target < 0 || idx == candidates.size()){
            return;
        }
        
        // Recursive Case
        
        // When candidates[idx] is included
        curr.push_back(candidates[idx]);
        findSol(idx, target - candidates[idx], curr, res, candidates);
        curr.pop_back();
        
        // When candidates idx is not included
        findSol(idx+1, target, curr, res, candidates);
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> curr;
        findSol(0, target, curr, res, candidates);
        return res;
    }
};