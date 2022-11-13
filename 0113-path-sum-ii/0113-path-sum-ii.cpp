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
    void allPaths(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& res){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL && targetSum - root->val == 0){
            temp.push_back(root->val);
            res.push_back(temp);
            temp.pop_back();
        }
            
        
        temp.push_back(root->val);
        allPaths(root->left, targetSum-root->val, temp, res);
        allPaths(root->right, targetSum-root->val, temp, res);
        temp.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> temp;
        vector<vector<int>> res;
        
        allPaths(root, targetSum, temp, res);
        
        return res;
    }
};