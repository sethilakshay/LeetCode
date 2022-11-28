class Solution {
public:
    struct TrieNode{
        TrieNode* child[26] = {NULL};
        string word = "";
    };
    
    TrieNode* root = new TrieNode();
    
    //Function to build the tree
    void buildTree(vector<string>& products){
        
        for(int i=0; i<products.size(); i++){
            
            TrieNode* temp = root;
            
            for(char c: products[i]){
                if(temp->child[c-'a'] == NULL){
                    temp->child[c-'a'] = new TrieNode();
                }
                temp = temp->child[c-'a'];
            }
            temp->word = products[i];
        }
    }
    
    void DFS(TrieNode* root, int limit, vector<string>& res){
        if(root == NULL)
            return;
        
        if(res.size() == limit)
            return;
        
        if(root->word.size() > 0)
            res.push_back(root->word);
        
        for(int i=0; i<26; i++){
            DFS(root->child[i], limit, res);
        }
    }
    
    vector<string> findWords(TrieNode* root, int limit){
        vector<string> res;
        DFS(root, limit, res);
        return res;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //Building the Trie Tree
        buildTree(products);
        TrieNode* temp = root;
        
        vector<vector<string>> res;

        for(char c: searchWord){

            if(temp != NULL && temp->child[c-'a'] != NULL){
                temp = temp->child[c-'a'];
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