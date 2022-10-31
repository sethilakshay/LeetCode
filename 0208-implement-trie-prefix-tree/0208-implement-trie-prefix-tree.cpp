class Trie {
public:
    struct TrieNode {
        TrieNode* child[26] = {NULL};
        bool isWord = false;
    };
    
    Trie(){
        
    }
    
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        
        TrieNode* temp = root;
        
        for(int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';
            
            if(temp->child[idx] == NULL)
                temp->child[idx] = new TrieNode();
            
            temp = temp->child[idx];
        }
        
        temp->isWord = true;
        
    }
    
    bool search(string word) {
        
        TrieNode* temp = root;
        
        for(int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';
            
            if(temp->child[idx] == NULL)
                return false;
            
            temp = temp->child[idx];
        }
        
        return temp->isWord;
    }
    
    bool search_deep(TrieNode* root){
        //Base Case
        if(root == NULL)
            return false;
        
        if(root->isWord == true)
            return true;
        
        //Recursion
        for(int i=0; i<26; i++){
            
            if(search_deep(root->child[i])){
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* temp = root;
        
        for(int i=0; i<prefix.size(); i++){
            int idx = prefix[i] - 'a';
            
            if(temp->child[idx] == NULL)
                return false;
            
            temp = temp->child[idx];
        }
        
        return search_deep(temp);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */