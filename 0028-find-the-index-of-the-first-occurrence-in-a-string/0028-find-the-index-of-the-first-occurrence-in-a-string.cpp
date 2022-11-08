class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int chck = needle.size();
        if(chck == 0)
            return 0;
        
        if(chck > haystack.size())
            return -1;
        
        for(int i=0; i<haystack.size() - chck + 1; i++){
            
            if(haystack.substr(i, chck) == needle){
                return i;
            }
            
        }
        return -1;
    }
};