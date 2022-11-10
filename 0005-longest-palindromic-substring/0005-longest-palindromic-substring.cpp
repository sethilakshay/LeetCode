class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size(), maxC = 0;
        string res = "";
        
        for(int i=0; i<n; i++){
            
            int start = i, end = i;
            while(start >= 0 && end <n && s[start] == s[end]){
                int strLen = end-start+1;
                
                if(strLen > maxC){
                    maxC = strLen;
                    res = s.substr(start, strLen);
                }
                start--;
                end++;
            }
            
            start = i, end = i+1;
            while(start >= 0 && end <n && s[start] == s[end]){
                int strLen = end-start+1;
                
                if(strLen > maxC){
                    maxC = strLen;
                    res = s.substr(start, strLen);
                }
                start--;
                end++;
            }
        }
        return res;
    }
};