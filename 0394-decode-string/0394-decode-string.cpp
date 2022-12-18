class Solution {
public:
    string decodeString(string s) {
        
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            
            if(s[i] != ']'){
                stk.push(s[i]);
            }

            else{
                string curr_str = "";
                while(stk.top() != '['){
                    curr_str = stk.top() + curr_str;
                    stk.pop();
                }
                
                stk.pop();  //To remove this [
                string num = "";
                
                while(!stk.empty() && isdigit(stk.top())){
                    num = stk.top() + num;
                    stk.pop();
                }
                
                int repeat = stoi(num);
                while(repeat--){
                    
                    for(int k=0; k<curr_str.size(); k++)
                        stk.push(curr_str[k]);
                }
            }
        }
        
        string res = "";
        while(!stk.empty()){
            res = stk.top() + res;
            stk.pop();
        }
        
        return res;
    }
};