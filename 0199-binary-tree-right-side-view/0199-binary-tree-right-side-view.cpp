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
        q.push(root);
        
        vector<int> res;
        res.push_back(root->val);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> curr;
            
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL){
                    q.push(temp->left);
                    curr.push_back(temp->left->val);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                    curr.push_back(temp->right->val);
                }
            }
            
            if(!curr.empty()){
                res.push_back(curr.back());
            }
        }
        return res;
    }
};