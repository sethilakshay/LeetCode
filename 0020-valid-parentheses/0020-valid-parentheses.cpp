class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> bracket_map;
        bracket_map[')'] = '(';
        bracket_map['}'] = '{';
        bracket_map[']'] = '[';
        
        stack<char> stk;
        
        for(int i=0; i<s.size(); i++){
            
            if(bracket_map.find(s[i]) != bracket_map.end()){
                
                if(!stk.empty() && stk.top() == bracket_map[s[i]])
                    stk.pop();
                else
                    return false;
            }
            
            else{
                stk.push(s[i]);
            }
        }
        
        return stk.empty() ? true : false;
    }
};