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
    void encode(TreeNode* root, string& out){
        if(root == NULL){
            out.push_back('n');
            out.push_back(',');
            return;
        }
        
        out += to_string(root->val);
        out.push_back(',');
        
        encode(root->left, out);
        encode(root->right, out);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string out = "";
        encode(root, out);
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
        
        while(data[idx] != 'n' && data[idx] != ','){
            currNum += data[idx];
            idx++;
        }
        
        TreeNode* root = new TreeNode(stoi(currNum));
        
        root->left = buildTree(idx, data);
        root->right = buildTree(idx, data);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return buildTree(idx, data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));