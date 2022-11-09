class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> freq(256, 0);
        int res = 0, j = 0;
        for(int i=0; i<s.size(); i++){
            
            while(freq[s[j]] == 0 && j<s.size()){
                freq[s[j]]++;
                j++;
            }
            
            freq[s[i]]--;
            res = max(res, j-i);
            
            if(j == s.size())
                break;
        }
        return res;
    }
};