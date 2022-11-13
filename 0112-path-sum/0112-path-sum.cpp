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
    void checkSum(TreeNode* root, int targetSum, bool& res){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL && targetSum - root->val == 0){
            res = true;
            return;
        }
            
        
        checkSum(root->left, targetSum - root->val, res);
        checkSum(root->right, targetSum - root->val, res);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        checkSum(root, targetSum, res);
        return res;
    }
};