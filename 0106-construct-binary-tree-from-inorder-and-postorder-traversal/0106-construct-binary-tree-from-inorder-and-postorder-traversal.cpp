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
    TreeNode* TreeBuild(vector<int>& inorder, int i1, int i2, vector<int>& postorder, int p1, int p2, unordered_map<int, int>& hash_map){
        if(i1>i2)
            return NULL;
        
        int rootVal = postorder[p2];
        
        TreeNode* root = new TreeNode(rootVal);
        
        int pos = hash_map[rootVal] - i1;
        
        root->left = TreeBuild(inorder, i1, i1+pos-1, postorder, p1, p1+pos-1, hash_map);
        root->right = TreeBuild(inorder, i1+pos+1, i2, postorder, p1+pos, p2-1, hash_map);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        if(n == 0)
            return NULL;
        
        unordered_map<int, int> hash_map;
        
        for(int i=0; i<n; i++){
            hash_map[inorder[i]] = i;
        }
        
        return TreeBuild(inorder, 0, n-1, postorder, 0, n-1, hash_map);
    }
};