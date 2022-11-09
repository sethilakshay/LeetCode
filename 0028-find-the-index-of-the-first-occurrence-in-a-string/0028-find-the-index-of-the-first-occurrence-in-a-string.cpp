class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int chck = needle.size();
        if(chck == 0)
            return 0;
        
        if(chck > haystack.size())
            return -1;
        
        for(int i=0; i<haystack.size() - chck + 1; i++){
            
            for(int j=0; j<needle.size(); j++){
                
                if(needle[j] != haystack[i+j]){
                    break;
                }
                
                if(j == needle.size()-1){
                    return i;
                }
                 
            }
            
        }
        return -1;
    }
};