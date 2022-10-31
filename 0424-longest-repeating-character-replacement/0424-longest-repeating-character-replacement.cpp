class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> freq(26, 0);
        int i = 0, j = 0, n = s.size();
        int max_freq = 0, window = 0, res = 0;
        
        while(i<=j && j<n){
            
            window = j-i+1;
            
            freq[s[j] - 'A']++;
            max_freq = max(max_freq, freq[s[j] - 'A']);
            
            if(window-max_freq <= k){
                res = max(res, window);
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