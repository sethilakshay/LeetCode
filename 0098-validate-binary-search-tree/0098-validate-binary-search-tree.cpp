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
    void chckRange(TreeNode* root, long min_v, long max_v){
        if(root == NULL || !res){
            return;
        }
        
        if(!(min_v < root->val && root->val < max_v))
            res = false;
        
        chckRange(root->left, min_v, root->val);
        chckRange(root->right, root->val, max_v);
        
    }
    bool isValidBST(TreeNode* root) {
        chckRange(root, LONG_MIN, LONG_MAX);
        return res;
    }
};