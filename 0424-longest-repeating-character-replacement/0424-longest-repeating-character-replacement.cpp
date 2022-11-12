class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int n = s.size(), i = 0, j = 0;
        int res = 0, window = 0, max_freq = 0;
        
        while(i<=j && j<n){
            
            window = j-i+1;
            freq[s[j] - 'A']++;
            
            max_freq = max(max_freq, freq[s[j] - 'A']);
            
            if(window - max_freq <= k){
                res = max(window, res);
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