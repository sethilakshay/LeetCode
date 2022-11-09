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
    
    void checkTree(TreeNode* root, long min, long max){
        if (root == NULL || !res)
            return;
        
        if(root->val <= min || max <= root->val){
            res = false;
        }
            
        checkTree(root->left, min, root->val);
        checkTree(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        
        checkTree(root, LONG_MIN, LONG_MAX);
        return res;
    }
};