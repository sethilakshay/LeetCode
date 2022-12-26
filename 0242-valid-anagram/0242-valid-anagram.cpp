class Solution {
public:
    // TC: O(N)
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        vector<int> dict(26, 0);
        for (int i = 0; i < s.size(); i++) {
            dict[s[i] - 'a']++;
        }
        
        for (int j = 0; j < t.size(); j++) {
            dict[t[j] - 'a']--;
            if (dict[t[j] - 'a'] < 0) {
                return false;
            }
        }
            
        return true;
    } 
};