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
    // Non Recursive BFS Solution
    // Using stack
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            TreeNode* temp = stk.top();
            stk.pop();
            
            if(temp != NULL){
                TreeNode* swap = temp->left;
                temp->left = temp->right;
                temp->right = swap;
                
                stk.push(temp->left);
                stk.push(temp->right);
            }
        }
        return root;
    }
};