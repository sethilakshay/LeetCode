class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.size()-1, j = b.size()-1, carry = 0, curr_bit = 0;
        string res = "";
        
        while(i >= 0 && j >= 0){
            
            curr_bit = ((a[i] - '0') + (b[j] - '0') + carry)%2;
            carry = ((a[i] - '0') + (b[j] - '0') + carry)/2;
            
            res = to_string(curr_bit) + res;
            
            i--;
            j--;
        }
        
        while(i >= 0){
            curr_bit = ((a[i] - '0') + carry)%2;
            carry = ((a[i] - '0') + carry)/2;
            
            res = to_string(curr_bit) + res;
            i--;
        }
        
        while(j >= 0){
            curr_bit = ((b[j] - '0') + carry)%2;
            carry = ((b[j] - '0') + carry)/2;
            
            res = to_string(curr_bit) + res;
            j--;
        }
        
        if(carry==1)
            res = to_string(carry) + res;
        
        return res;
    }
};