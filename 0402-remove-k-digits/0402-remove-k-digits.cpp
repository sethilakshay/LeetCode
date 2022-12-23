class Solution {
public:
    string removeKdigits(string& num, int k) {
        if(k >= num.size()){
            return "0";
        }
        
        // Maintain a monotonic stack
        stack<char> stk;
        stk.push(num[0]);
        
        for(int i=1; i<num.size(); i++){
            while(!stk.empty() && stk.top() > num[i] && k > 0){
                k--;
                stk.pop();
            }
            
            if(stk.size() == 1 && stk.top() == '0'){
                stk.pop();
            }
            
            stk.push(num[i]);
        }
        
        string res = "";
        while(!stk.empty() && k > 0){
            stk.pop();
            k--;
        }
        
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res == "" ? "0" : res;
    }
};