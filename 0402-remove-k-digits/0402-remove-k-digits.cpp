class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()){
            return "0";
        }
        
        int n = num.size(), i = 1;
        stack<char> stk;
        stk.push(num[0]);
        
        while(i<n){
            
            while(!stk.empty() && stk.top() > num[i] && k > 0){
                stk.pop();
                k--;
            }
            
            if(stk.size() == 1 && stk.top() == '0'){
                stk.pop();
            }
            
            stk.push(num[i]);
            i++;
        }
        
        while(!stk.empty() && k>0){
            stk.pop();
            k--;
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