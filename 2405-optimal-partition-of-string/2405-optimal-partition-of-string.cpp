class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), res = 0;
        
        set<char> char_chck;
        for(int i = 0; i<n; i++){
            
            if(char_chck.find(s[i]) != char_chck.end()){
                res++;
                char_chck.clear();
            }
            
            char_chck.insert(s[i]);
        }
        
        return res+1;
        
    }
};