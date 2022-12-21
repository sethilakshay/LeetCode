class Solution {
public:
    string removeKdigits(string& num, int k) {
        
        stack<char> stk;
        stk.push(num[0]);
        
        for(int i=1; i<num.size(); i++){
            
            // To ensure that we have a monotonic increasing stack
            while(!stk.empty() && stk.top() > num[i] && k > 0){
                k--;
                stk.pop();
            }
            
            // To pop the leading zeros
            if(stk.size() == 1 && stk.top() == '0'){
                stk.pop();
            }
            
            stk.push(num[i]);
        }
        
        // To pop the largest elemets stored at the stack top
        while(!stk.empty() && k > 0){
            k--;
            stk.pop();
        }
        
        string res = "";
        
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res == "" ? "0" : res;
    }
};