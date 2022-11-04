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
        
        res.push_back({q.front()->val});
        
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
                res.push_back(vec);
            }
        }
        
        int start = 0, end = res.size()-1;
        vector<int> temp;
        
        while(start<end){
            temp = res[start];
            res[start] = res[end];
            res[end] = temp;
            
            start++;
            end--;
        }
        return res;
    }
};