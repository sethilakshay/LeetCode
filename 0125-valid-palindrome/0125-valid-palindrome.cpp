class Solution {
public:
    bool isAlphanumeric(char c){
        
        return (('a'<=c && c<= 'z') || ('0'<=c && c<= '9'));
        
    }
    bool isPalindrome(string s) {
        
        int start = 0, end = s.size()-1;
        
        while(start <= end){
            
            if('A' <= s[start] && s[start] <= 'Z'){
                s[start] = s[start] - 'A' + 'a';
            }
            
            if('A' <= s[end] && s[end] <= 'Z'){
                s[end] = s[end] - 'A' + 'a';
            }
            
            if(!isAlphanumeric(s[start])){
                start++;
                continue;
            }
                
            
            if(!isAlphanumeric(s[end])){
                end--;
                continue;
            }
            
            if(s[start] != s[end]){
                cout<<s[start]<<s[end];
                return false;
            }
            
            start++;
            end--;
        }
        return true;
    }
};