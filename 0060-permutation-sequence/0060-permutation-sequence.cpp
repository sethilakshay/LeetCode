class Solution {
public:
    string getPermutation(int n, int k) {
        
        string res = "";
        
        vector<char> digits(n, 0);
        int fact = 1, curr;
        
        for(int i=1; i<n; i++){
            digits[i-1] = i+'0';
            fact *= i;
        }
        digits[n-1] = n+'0';
        
        int tempK = k-1;
        while(true){
            
            curr = tempK/fact;
            
            res.push_back(digits[curr]);
            digits.erase(digits.begin() + curr);
            
            if(digits.empty())
                break;
            
            tempK = tempK%fact;
            fact = fact/digits.size();
        }
        return res;
    }
};