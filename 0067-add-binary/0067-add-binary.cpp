class Solution {
public:
    string addBinary(string a, string b) {
        
        string res = "";
        int i = a.size()-1, j = b.size()-1, carry = 0, currSum;
        
        while(i >= 0 && j >= 0){
            currSum = ((a[i] - '0') + (b[j] - '0') + carry);
            carry = currSum/2;
            
            res.push_back(currSum%2 + '0');   
            
            i--;
            j--;
        }
        
        while(i >= 0){
            currSum = ((a[i] - '0') + carry);
            carry = currSum/2;
            
            res.push_back(currSum%2 + '0');      
            
            i--;
        }
        
        while(j >= 0){
            currSum = ((b[j] - '0') + carry);
            carry = currSum/2;
            
            res.push_back(currSum%2 + '0');     
            
            j--;
        }
        
        while(carry > 0){
            res.push_back((carry%2) + '0');
            carry = carry/2;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};