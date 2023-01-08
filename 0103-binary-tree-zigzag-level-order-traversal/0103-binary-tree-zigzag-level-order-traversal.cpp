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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        
        if(root == NULL){
            return {};
        }
        
        q.push(root);
        res.push_back({root->val});
        
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
                res.push_back(curr);
            }
        }
        
        for(int i=1; i<res.size(); i+= 2){
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};