class Solution {
public:
    
    struct TrieNode{
        TrieNode* child[26] = {NULL};
        string word = "";
    };
    // Initializing the TrieNode
    TrieNode* root = new TrieNode();
    
    void buildTrie(string& str){
        TrieNode* temp = root;
        for(char c: str){
            if(temp->child[c-'a'] == NULL){
                temp->child[c-'a'] = new TrieNode();
            }
            temp = temp->child[c-'a'];
        }
        temp->word = str;
    }
    
    void searchTrie(int& idx, vector<vector<string>>& res, TrieNode* node){
        if(node == NULL){
            return;
        }
        
        if(res[idx].size() == 3){
            return;
        }
        
        if(node->word != ""){
            res[idx].push_back(node->word);
        }
        
        for(int i=0; i<26; i++){
            TrieNode* temp = node->child[i];
            searchTrie(idx, res, temp);
        }
    }
    
    void dfs(string& searchWord, vector<vector<string>>& res){
        TrieNode* temp = root;
        int idx = -1;
        
        for(char c: searchWord){
            res.push_back(vector<string>());
            idx++;
            
            if(temp != NULL && temp->child[c-'a'] != NULL){
                temp = temp->child[c-'a'];
            }
            else{
                temp = NULL;
                continue;
            }

            searchTrie(idx, res, temp);
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(string str: products){
            buildTrie(str);
        }
        
        vector<vector<string>> res;    
        dfs(searchWord, res);
    
        return res;
    }
};