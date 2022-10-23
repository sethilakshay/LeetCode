class Solution {
public:
    //Worst case TC: O(N^2)
    string longestPalindrome(string s) {
        int n = s.size(), maxC = 0;
        string res;
        
        for(int i=0; i<n; i++){ 
            
            //For odd length strings
            int start = i, end = i;
            while((start>=0) && (end<n) && (s[start]==s[end])){
                
                int str_len = end-start+1;
                if(str_len > maxC){
                        maxC = str_len;
                        res = s.substr(start, str_len);
                }
                    
                start--;
                end++;
            }
            
            //For even length strings
            start = i, end = i+1;
            while((start>=0) && (end<n) && (s[start]==s[end])){
                
                int str_len = end-start+1;
                if(str_len > maxC){
                        maxC = str_len;
                        res = s.substr(start, str_len);
                }
                    
                start--;
                end++;
            }
            
        }
        return res;
    }
};