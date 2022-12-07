class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size(), maxC = 0;
        string res = "";
        for(int i=0; i<n; i++){
            
            int start = i;
            int end = i;
            
            while(start >= 0 && end<n && s[start]==s[end]){
                
                if(end-start+1 > maxC){
                    maxC = end-start+1;
                    res = s.substr(start, maxC);
                }
                start--;
                end++;
            }
            
            start = i;
            end = i + 1;
            
            while(start >= 0 && end<n && s[start]==s[end]){
                
                if(end-start+1 > maxC){
                    maxC = end-start+1;
                    res = s.substr(start, maxC);
                }
                start--;
                end++;
            }
        }
        return res;
    }
};