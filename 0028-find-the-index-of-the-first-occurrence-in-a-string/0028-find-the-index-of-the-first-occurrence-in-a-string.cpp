class Solution {
public:
    vector<int> lps(string pattern){
        
        int n = pattern.size(), j = 0;
        vector<int> kmp_lps(n, 0);
        
        for(int i=1; i<n; i++){
            j = kmp_lps[i-1];
            
            while(j>0 && pattern[i] != pattern[j]){
                j = kmp_lps[j-1];
            }
            if(pattern[i] == pattern[j]){
                j++;
            }
            kmp_lps[i] = j;
        }
        return kmp_lps;
        
    }
    int strStr(string haystack, string needle) {
        
        vector<int> kmp_pattern = lps(needle);
        
        int j = 0, i = 0, res = -1;
        while(i<haystack.size()){
            
            if(haystack[i] == needle[j]){
                j++;
                i++;
            }
            else{
                if(j != 0)
                    j = kmp_pattern[j-1];
                else
                    i++;
            }
            
            if(j == needle.size()){
                res = i - j;
                break;
            }
        }
        return res;
    }
};