class Solution {
public:
    bool isAlphanumeric(char c){
        
        return (('A'<=c && c<= 'Z') || ('a'<=c && c<= 'z') || ('0'<=c && c<= '9'));
        
    }
    bool isPalindrome(string s) {
        
        int start = 0, end = s.size()-1;
        
        while(start <= end){
            if(!isAlphanumeric(s[start])){
                start++;
                continue;
            }
                
            if(!isAlphanumeric(s[end])){
                end--;
                continue;
            }
            
            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            
            start++;
            end--;
        }
        return true;
    }
};