class Solution {
public:
    vector<int> buildLPS(string s){
        
        int n = s.size();
        vector<int> lps(n, 0);
        
        for(int i=1; i<n; i++){
            int j = lps[i-1];
            
            while(j>0 && s[i] != s[j]){
                j = lps[j-1];
            }
            
            if(s[i] == s[j]){
                j++;
            }
            
            lps[i] = j;
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        
        vector<int> lps = buildLPS(needle);
        
        int i=0, j = 0;
        
        while(i<haystack.size()){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
            
            if(j == needle.size()){
                return i - j;
            }
        }
        return -1;
    }
};