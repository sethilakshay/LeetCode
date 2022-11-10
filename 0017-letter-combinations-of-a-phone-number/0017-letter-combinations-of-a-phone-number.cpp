class Solution {
public:
    unordered_map<char, string> mapping;
    vector<string> res;
    
    void buildWord(string& digits, string curr_str, int idx){
        
        if(curr_str.size() == digits.size()){
            res.push_back(curr_str);
            return;
        }
        
        for(char c: mapping[digits[idx]]){
            
            buildWord(digits, curr_str+c, idx+1);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {

        if(digits.size()==0){
            return {};
        }
        
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
    
        buildWord(digits, "", 0);
        
        return res;
    }
};