class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        
        for(int i=0; i<strs.size(); i++){
            int str_len = strs[i].size();
            
            res += to_string(str_len) + '@' + strs[i];
        }
        
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        int i, j;
        vector<string> res;
        
        for(i=0; i<s.size(); i){
            
            j = i;
            
            while(s[j] != '@'){
                j++;
            }
            
            int len_int = stoi(s.substr(i, j-i));
            
            res.push_back(s.substr(j+1, len_int));
            
            i = j + 1 + len_int;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));