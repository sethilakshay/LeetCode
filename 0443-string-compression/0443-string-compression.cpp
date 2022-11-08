class Solution {
public:
    int compress(vector<char>& chars) {
        
        stack<pair<char, int>> stk;
        
        stk.push(make_pair(chars[0], 1));
        
        for(int i=1; i<chars.size(); i++){
            
            if(stk.top().first == chars[i])
                stk.top().second++;
            
            else
                stk.push(make_pair(chars[i], 1));
        }
        
        string res = "";
        
        while(!stk.empty()){
            
            if(stk.top().second == 1){
                res = stk.top().first + res;
            }
            else{
                res = stk.top().first + to_string(stk.top().second) + res;
            }
            
            stk.pop();
        }
        chars = vector<char>(res.size());
        
        for(int i=0; i<res.size(); i++){
            chars[i] = res[i];
        }
        
        return res.size();
    }
};