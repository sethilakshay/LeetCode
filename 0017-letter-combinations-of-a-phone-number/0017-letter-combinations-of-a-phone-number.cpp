class Solution {
public:
    
    void findComb(string& digits, int idx, string curr, unordered_map<char, string>& hash_map,
    vector<string>& res){
        
        // Base Case
        if(curr.size() == digits.size()){
            res.push_back(curr);
            return;
        }
        
        // Recursive Case
        
        for(char c: hash_map[digits[idx]]){
            findComb(digits, idx + 1, curr + c, hash_map, res);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        
        unordered_map<char, string> hash_map;
        vector<string> res;
        
        hash_map['2'] = "abc";
        hash_map['3'] = "def";
        hash_map['4'] = "ghi";
        hash_map['5'] = "jkl";
        hash_map['6'] = "mno";
        hash_map['7'] = "pqrs";
        hash_map['8'] = "tuv";
        hash_map['9'] = "wxyz";
        
        findComb(digits, 0, "", hash_map, res);
        
        return res;
    }
};