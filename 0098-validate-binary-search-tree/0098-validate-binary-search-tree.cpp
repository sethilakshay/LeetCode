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
    bool isValidBST(TreeNode* root) {
        
        stack<TreeNode*> stk;
        TreeNode* prev = NULL;
        
        while(root != NULL || !stk.empty()){
            
            while(root != NULL){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            
            if(prev && prev->val >= root->val){
                return false;
            }
            
            prev = root;
            root = root->right;
        }
        return true;
    }
};