class Solution {
public:
    bool isPal(string str){
        int start = 0, end = str.size() - 1;
        
        while(start <= end){
            if(str[start] != str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void findPal(int idx, string& s, vector<string>& curr, vector<vector<string>>& res){
        // Base Case
        if(idx == s.size()){
            res.push_back(curr);
            return;
        }
        
        // Recursive Case
        string prefix = "";
        for(int i=idx; i<s.size(); i++){
            prefix += s[i];
            
            if(isPal(prefix)){
                
                curr.push_back(prefix);
                findPal(i+1, s, curr, res);
                curr.pop_back();
                
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> curr;
        
        findPal(0, s, curr, res);
        return res;
    }
};