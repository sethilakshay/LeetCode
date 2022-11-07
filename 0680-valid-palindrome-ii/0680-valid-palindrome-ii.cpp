class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size()-1;
        
        while(start <= end && s[start] == s[end]){
            start++;
            end--;
        }
        
        if(start > end)
            return true;
        
        int temp1 = start+1, temp2 = end;
        while(temp1 <= temp2 && s[temp1] == s[temp2]){
            temp1++;
            temp2--;
        }
        
        if(temp1 > temp2)
            return true;
        
        temp1 = start, temp2 = end-1;
        while(temp1 <= temp2 && s[temp1] == s[temp2]){
            temp1++;
            temp2--;
        }
        
        if(temp1 > temp2)
            return true;
        
        return false;
    }
};