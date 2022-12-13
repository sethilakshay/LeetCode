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
    TreeNode* finTree(vector<int>& inorder, int i1, int i2, vector<int>& preorder, int p1, int p2, unordered_map<int, int>& in_map){
        //Base Case
        if(i1>i2){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[p1]);
        int pos = in_map[preorder[p1]] - i1;
        
        root->left = finTree(inorder, i1, i1+pos-1, preorder, p1+1, p1+pos+1, in_map);
        root->right = finTree(inorder, i1+pos+1, i2, preorder, p1+pos+1, p2, in_map);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> in_map;
        int n = inorder.size();
        for(int i = 0; i<n; i++){
            in_map[inorder[i]] = i;
        }
        
        TreeNode* root = finTree(inorder, 0, n-1, preorder, 0, n-1, in_map);
        return root;
    }
};