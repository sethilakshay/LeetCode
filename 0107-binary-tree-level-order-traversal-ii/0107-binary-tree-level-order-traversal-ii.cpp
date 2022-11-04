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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        stack<vector<int>> stk;
        stk.push({q.front()->val});
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int> vec;
            
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left != NULL){
                    q.push(temp->left);
                    vec.push_back(temp->left->val);
                }
                
                if(temp->right != NULL){
                    q.push(temp->right);
                    vec.push_back(temp->right->val);
                }
            }
            
            if(vec.size() != 0){
                stk.push(vec);
            }
        }
        
        
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};