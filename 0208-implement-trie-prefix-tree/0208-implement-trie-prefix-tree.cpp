class Trie {
public:
    Trie() {
    }
    
    struct TrieNode{
        TrieNode* child[26] = {NULL};
        bool isWord = false;
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        
        TrieNode* temp = root;
        for(char c: word){
            if(temp->child[c-'a'] == NULL){
                temp->child[c-'a'] = new TrieNode();
            }
            temp = temp->child[c-'a'];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        
        TrieNode* temp = root;
        for(char c: word){
    
            if(temp->child[c-'a'] == NULL){
                return false;
            }
            temp = temp->child[c-'a'];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* temp = root;
        for(char c: prefix){
            if(temp->child[c-'a'] == NULL){
                return false;
            }
            temp = temp->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */