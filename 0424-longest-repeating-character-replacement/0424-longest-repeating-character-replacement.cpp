class Solution {
public:
    int characterReplacement(string s, int k) {

        vector <int> freq (26);
        int i=0, j = 0, n = s.size();
        int windowLen = 0, max_rep = 0, ans = 0;
        
        while(i<=j && j<n){
            
            windowLen = j-i+1;
            freq[s[j]-'A']++;
            
            max_rep = max(max_rep, freq[s[j]-'A']);
            
            if(windowLen - max_rep <= k)
                ans = max(ans, windowLen);
            
            else{
                freq[s[i]-'A']--;
                i++;
            }
            
            j++;
        }
        return ans;
    }
};