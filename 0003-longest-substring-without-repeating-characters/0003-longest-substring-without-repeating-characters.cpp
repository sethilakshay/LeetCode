class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), res = 0;
        vector<int> freq(256, 0);
        
        int i=0, j = 0;
        
        while(j<n){

            freq[s[j]]++;
            
            while(freq[s[j]] > 1 && i<=j){
                freq[s[i]]--;
                i++;
            }
            
            res = max(res, j-i+1);
            j++;
        }
        
        return res;
    }
};