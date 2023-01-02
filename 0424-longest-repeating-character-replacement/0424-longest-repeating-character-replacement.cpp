class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> freq(26, 0);
        int max_freq = 0, res = 1;
        
        int i=0, j=0;
        
        while(j<s.size() && i<=j){
            
            freq[s[j] - 'A']++;
            max_freq = max(max_freq, freq[s[j] - 'A']);
            
            if(j-i+1 - max_freq <= k){
                res = max(res, j-i+1);
            }
            else{
                freq[s[i] - 'A']--;
                i++;
            }
            
            j++;
        }
        return res;
    }
};