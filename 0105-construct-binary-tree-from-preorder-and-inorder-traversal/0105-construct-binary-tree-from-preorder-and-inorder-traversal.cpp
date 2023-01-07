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
    TreeNode* Tree(vector<int>& inorder, int i1, int i2, vector<int>& preorder, int p1, int p2, unordered_map<int, int>& in_map){
        if(i1 > i2){
            return NULL;
        }
        
        int elt = preorder[p1];
        int pos = in_map[elt] - i1;
        
        TreeNode* root = new TreeNode(elt);
        
        root->left = Tree(inorder, i1, i1 + pos-1, preorder, p1+1, p1+pos+1, in_map);
        root->right = Tree(inorder, i1+pos+1, i2, preorder, p1+pos+1, p2, in_map);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> in_map;
        
        for(int i=0; i<inorder.size(); i++){
            in_map[inorder[i]] = i;
        }
        
        return Tree(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, in_map);
    }
};