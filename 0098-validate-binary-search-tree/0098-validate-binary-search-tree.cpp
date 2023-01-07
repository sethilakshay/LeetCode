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
    TreeNode* prev = NULL;
    
    void inOrder(TreeNode* root){
        if(root == NULL || !res){
            return;
        }
        
        inOrder(root->left);
        if(prev && prev->val >= root->val){
            res = false;
            return;
        }
        
        prev = root;
        inOrder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return res;
    }
};