class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> map;
        
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        
        stack<char> stk;
        
        for(int i=0; i<s.size(); i++){
            
            if(map.find(s[i]) != map.end() && !stk.empty() && stk.top() == map[s[i]]){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};