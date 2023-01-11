/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findSum(TreeNode* root, int targetSum, vector<int>& curr, vector<vector<int>>& res){
        // Base Cases
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL && targetSum-root->val == 0){
            curr.push_back(root->val);
            res.push_back(curr);
            curr.pop_back();
            return;
        }
    
        // Recurisve Case
        curr.push_back(root->val);
        findSum(root->left, targetSum - root->val, curr, res);
        findSum(root->right, targetSum - root->val, curr, res);
        curr.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> curr;
        vector<vector<int>> res;
        findSum(root, targetSum, curr, res);
        return res;
    }
};