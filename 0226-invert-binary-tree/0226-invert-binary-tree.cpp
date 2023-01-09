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
    // Non Recursive BFS Solution
    // Using queues
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp != NULL){
                    TreeNode* swap = temp->left;
                    temp->left = temp->right;
                    temp->right = swap;

                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};