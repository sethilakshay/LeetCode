class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string res = "";
        
        for(int i=0; i<s.size(); i++){
            if(s[i] != ']'){
                stk.push(s[i]);
            }
            else{
                string curr = "";
                while(stk.top() != '['){
                    curr = stk.top() + curr;
                    stk.pop();
                }
                
                stk.pop(); // to remove [
                
                string num = "";
                
                while(!stk.empty() && isdigit(stk.top())){
                    num = stk.top() + num;
                    stk.pop();
                }
                
                int n = stoi(num);
                
                while(n > 0){
                    for(char c: curr){
                        stk.push(c);
                    }
                    n--;
                }
            }
        }
        
        while(!stk.empty()){
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};