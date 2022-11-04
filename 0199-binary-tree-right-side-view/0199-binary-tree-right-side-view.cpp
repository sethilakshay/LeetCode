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
    void rightView(TreeNode* root, vector<int>& res, int lvl){
        if(root == NULL){
            return;
        }
        
        if(lvl == res.size()){
            res.push_back(root->val);
        }
        
        rightView(root->right, res, lvl+1);
        rightView(root->left, res, lvl+1);
        
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        rightView(root, res, 0);
        
        return res;
    }
};