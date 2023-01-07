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
    void checkBST(TreeNode* root, long min, long max){
        if(!res || root == NULL){
            return;
        }
        
        if(root->val <= min || root->val >= max){
            res = false;
            return;
        }
        
        checkBST(root->left, min, root->val);
        checkBST(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        
        checkBST(root, LONG_MIN, LONG_MAX);
        return res;
    }
};