/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Level-Order Binary Tree serialization and De-serialization
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string out = "";
        if(root == NULL){
            return out;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        out += to_string(root->val);
        out.push_back(',');
        
        while(!q.empty()){
            
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left != NULL){
                    q.push(temp->left);
                    out += to_string(temp->left->val);
                }
                else{
                    out.push_back('n');
                }
                out.push_back(',');
                
                if(temp->right != NULL){
                    q.push(temp->right);
                    out += to_string(temp->right->val);
                }
                else{
                    out.push_back('n');
                }
                out.push_back(',');
            }
        }
        return out;
    }

    TreeNode* buildTree(int& idx, string& data){
        if(idx == data.size()){
            return NULL;
        }
        
        if(data[idx] == ','){
            idx++;
        }
        
        if(data[idx] == 'n'){
            idx++;
            return NULL;
        }
        
        string currNum = "";
        while(data[idx] != ','){
            currNum.push_back(data[idx]);
            idx++;
        }
        
        return new TreeNode(stoi(currNum));
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return NULL;
        }
        
        int idx = 0;
        TreeNode* root = buildTree(idx, data);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                temp->left = buildTree(idx, data);
                if(temp->left != NULL)
                    q.push(temp->left);
                
                temp->right = buildTree(idx, data);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));