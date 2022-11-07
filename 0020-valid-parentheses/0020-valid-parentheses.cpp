class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> hash_map;
        stack<char> stk;
        
        hash_map[')'] = '(';
        hash_map['}'] = '{';
        hash_map[']'] = '[';
        
        for(int i=0; i<s.size(); i++){
            
            if(hash_map.find(s[i]) != hash_map.end()){
                
                if(stk.empty() || hash_map[s[i]] != stk.top())
                    return false;
                else 
                    stk.pop();
            }
            
            else
                stk.push(s[i]);
        }
        return stk.empty();
        
    }
};