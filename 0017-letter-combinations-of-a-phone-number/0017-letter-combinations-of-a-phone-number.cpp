class Solution {
public:
    vector<string> res;
    unordered_map<char, string> mapping;
    
    void all_comb(string& digits, int idx, string currStr){
        //Base Case
        if(currStr.size() == digits.size()){
            res.push_back(currStr);
            return;
        }

        //Recursion
        for(char c: mapping[digits[idx]]){
            all_comb(digits, idx+1, currStr + c);
        }
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
        
        
        all_comb(digits, 0, "");
        
        return res;
    }
};