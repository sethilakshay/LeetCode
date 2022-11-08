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
                string temp = "";
                while(stk.top() != '['){
                    temp = stk.top() + temp;
                    stk.pop();
                }
                
                stk.pop();  //To remove this [
                
                string num = "";
                while(!stk.empty() && '0' <=stk.top() && stk.top()<= '9'){
                    num = stk.top() + num;
                    stk.pop();
                }
                
                int temp_n = stoi(num);
                
                while(temp_n > 0){
                    
                    for(int k=0; k<temp.size(); k++)
                        stk.push(temp[k]);
            
                    temp_n--;
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