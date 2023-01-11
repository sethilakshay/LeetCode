class Solution {
public:
    // Note (Very Important)
    // While normally we increment num by doing num++ and decrement by doing num--
    // Here in KMP, to construct the LPS array, we increment the ptr of pattern (say j)
    // as usual by doing j++, but decrement j everywhere by doing j = lps[j-1]
    vector<int> buildLPS(string& s){
        int n = s.size(), j = 0;
        vector<int> lps(n, 0);
        
        for(int i=1; i<n; i++){
            // Initial assignment of j, now checks will be made if this is valid or not.
            j = lps[i-1];
            
            // First check for s[i] != s[j], then decrement j such that it becomes 0 or s[i]==s[j]
            // Here we go back by not doing j--, but assigning it the previous lps value
            // j = lps[j-1] (Remember that j is initally set to lps[i-1])
            while(j>0 && s[i] != s[j])
                j = lps[j-1];
            
            // If s[i] matches with s[j], increment j
            // Say if s = "AAA" and i=1 => j = lps[i-1] = lps[0] = 0. Incrementing j will make it 1.
            // Now, if i=2 => j = lps[i-1] = lps[1] = 1. Incrementing j will make it 2.
            // This incremented j value will get assigned to lps[i].
            if(s[i] == s[j])
                j++;
            
            lps[i] = j;
        }
        return lps;
    }
    int strStr(string haystack, string needle) {

        vector<int> lps = buildLPS(needle);
        
        int i = 0, j = 0;
        
        while(i<haystack.size()){
            // As long as they match, increment both
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                // If j is currently positive, decrement j and see if now the pattern matches
                if(j != 0){
                    j = lps[j-1];
                }
                // If j=0, means we are at the start of pattern therefore i++
                else{
                    i++;
                }
            }
            
            // If we have reached the end of j, means pattern matched.
            if(j == needle.size()){
                return i - j;
            }
        }
        return -1;
    }
};