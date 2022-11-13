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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        TreeNode* temp = root;
        q.push(temp);
        res.push_back({temp->val});
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int> temp;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left != NULL){
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                
                if(curr->right != NULL){
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
            }
            
            if(temp.size() != 0)
                res.push_back(temp);   
        }
        return res;
    }
};