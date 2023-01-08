class Solution {
public:
    string addBinary(string a, string b) {
        
        int sum = 0, carry = 0;
        int i = a.size()-1, j = b.size()-1;
        
        string res = "";
        
        while(i >= 0 && j >= 0){
            
            sum = (a[i] - '0') + (b[j] - '0') + carry;
            carry = sum/2;   
            res = to_string(sum%2) + res;
            
            i--;
            j--;
        }
        
        while(i >= 0){
            sum = (a[i] - '0') + carry;
            carry = sum/2;   
            res = to_string(sum%2) + res;
            
            i--;
        }
        
        while(j >= 0){
            sum = (b[j] - '0') + carry;
            carry = sum/2;   
            res = to_string(sum%2) + res;
            
            j--;
        }
        
        while(carry > 0){
            sum = carry;
            
            carry = carry/2;
            res = to_string(sum%2) + res;
        }
        
        return res;
    }
};