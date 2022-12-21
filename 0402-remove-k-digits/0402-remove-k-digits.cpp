class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()){
            return "0";
        }
        
        if(k == 0){
            return num;
        }
        
        stack<char> stk;    // Maintain a monotonic stack
        stk.push(num[0]);
        
        for(int i=1; i<num.size(); i++){
            while(!stk.empty() && stk.top() > num[i] && k>0){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
            
            if(stk.size() == 1 && num[i] == '0'){
                stk.pop();   
            }
        }
        
        // If the entire stack is monotonic, pop the last k elements
        while(!stk.empty() && k > 0){
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