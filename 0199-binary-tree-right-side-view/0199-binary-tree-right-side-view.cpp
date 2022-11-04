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
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        
        if(root == NULL){
            return {};
        }
        
        res.push_back(root->val);
        
        while(!q.empty()){
            
            int n = q.size();
            int val = INT_MIN;
            
            for(int i=0; i<n; i++){
    
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left != NULL){
                    q.push(temp->left);
                    val = temp->left->val;
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                    val = temp->right->val;
                }
            }
            
            if(val != INT_MIN){
                res.push_back(val);
            }
        }
        return res;
    }
};