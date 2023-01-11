/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Exploiting the property of BST to solve this
    // Where left element is less than root and right element is greater than root
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if((root->val - p->val) > 0 && (root->val - q->val) > 0){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if ((root->val - p->val) < 0 && (root->val - q->val) < 0){
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            return root;
        }
    }
};