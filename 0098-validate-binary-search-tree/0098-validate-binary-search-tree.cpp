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
    bool res = true;
    
    void TreeCheck(TreeNode* root, long min, long max){
        if(root == NULL || !res){
            return;
        }
        
        if(root->val <= min || max <= root->val){
            res = false;
        }
        
        TreeCheck(root->left, min, root->val);
        TreeCheck(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        
        TreeCheck(root, LONG_MIN, LONG_MAX);
        return res;
    }
};