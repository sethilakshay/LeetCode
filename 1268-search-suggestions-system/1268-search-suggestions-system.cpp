class Solution {
public:
    struct TrieNode{
        TrieNode* child[26] = {NULL};
        string word = "";
    };
    
    TrieNode* root = new TrieNode();
    
    void buildTree(vector<string>& products){
        
        for(int i=0; i<products.size(); i++){
            TrieNode* temp = root;
            
            for(int j=0; j<products[i].size(); j++){
                
                int idx = products[i][j] - 'a';
                if(temp->child[idx] == NULL){
                    temp->child[idx] = new TrieNode();
                }
                temp = temp->child[idx];
            }
            temp->word = products[i];
        }
    }
    
    void DFS(TrieNode* root, int limit, vector<string>& res){
        if(root == NULL)
            return;
        
        if(res.size() == limit)
            return;
        
        if(root->word.size() > 0){
            res.push_back(root->word);
        }
        
        for(int i=0; i<26; i++){
            DFS(root->child[i], limit, res);
        }
        return;
    }
    
    vector<string> findWords(TrieNode* root, int limit){
        vector<string> res;
        DFS(root, limit, res);
        return res;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        buildTree(products);
        
        vector<vector<string>> res;
        
        TrieNode* temp = root;
        
        for(char c: searchWord){
            int idx = c - 'a';
            if(temp != NULL && temp->child[idx] != NULL){
                temp = temp->child[idx];
                res.push_back(findWords(temp, 3));
            }
            else{
                temp = NULL;
                res.push_back({});
            }
        }
        return res;
    }
};