class Solution {
public:
    struct TrieNode{
        TrieNode* child[26] = {NULL};
        string word = "";
    };
    
    TrieNode* root = new TrieNode;
    
    void buidTrie(string str){
        TrieNode* temp = root;
        
        for(char c: str){
            
            if(temp->child[c - 'a'] == NULL){
                temp->child[c - 'a'] = new TrieNode();
            }    
            temp = temp->child[c - 'a'];
        }
        temp->word = str;
    }
    
    void search(TrieNode* node, vector<string>& curr, int n){
        
        if(curr.size() == n){
            return;
        }
        
        if(node == NULL){
            return;
        }
        
        if(node->word != ""){
            curr.push_back(node->word);
        }
        
        // Recursive Case;
        for(int i=0; i<26; i++){
            search(node->child[i], curr, n);
        }
    }
    
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(string prod: products){
            buidTrie(prod);
        }
        
        vector<vector<string>> res;
        TrieNode* temp = root;
        
        for(char c: searchWord){
            
            vector<string> curr;
            if(temp != NULL && temp->child[c-'a'] != NULL){
                temp = temp->child[c - 'a'];
            }
            else{
                temp = NULL;
            }
            search(temp, curr, 3);
            res.push_back(curr);
        }
        return res;
    }
};