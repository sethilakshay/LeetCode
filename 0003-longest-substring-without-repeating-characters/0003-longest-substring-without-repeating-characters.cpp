class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), res = 0;
        vector<int> freq(256, 0);
        
        int i=0, j = 0;
        
        while(i<=j && j<n){
            
            if(freq[s[j]] == 0){
                freq[s[j]]++;
                j++;
            }
            else{
                freq[s[i]]--;
                i++;
            }
            res = max(res, j-i);
        }
        
        return res;
    }
};