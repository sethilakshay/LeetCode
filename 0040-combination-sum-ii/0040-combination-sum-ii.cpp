class Solution {
public:
    void findSum(int idx, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res){
        // Base Case
        if(target == 0){
            res.push_back(curr);
            return;
        }
        
        if(target<0 || idx == candidates.size()){
            return;
        }
        
        // Recursive Case
        curr.push_back(candidates[idx]);
        findSum(idx+1, candidates, target - candidates[idx], curr, res);
        curr.pop_back();
        
        int i = idx;
        while(i<candidates.size() && candidates[i] == candidates[idx]){
            i++;
        }
        findSum(i, candidates, target, curr, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> curr;
        
        sort(candidates.begin(), candidates.end());
        
        findSum(0, candidates, target, curr, res);
        return res;
    }
};