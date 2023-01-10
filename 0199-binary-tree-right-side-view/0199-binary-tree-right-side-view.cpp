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
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        
        queue<TreeNode*> q;
        vector<int> res;
        
        q.push(root);
        res.push_back(root->val);
        
        while(!q.empty()){
            
            int n = q.size(), rightVal = INT_MIN;
            
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left != NULL){
                    q.push(temp->left);
                    rightVal = temp->left->val;
                }
                
                if(temp->right != NULL){
                    q.push(temp->right);
                    rightVal = temp->right->val;
                }
            }
            if(rightVal != INT_MIN){
                res.push_back(rightVal);
            }
        }
        return res;
    }
};