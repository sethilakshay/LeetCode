class Solution {
public:
    string getPermutation(int n, int k) {
        int currDigit, fact=1;
        string res = "";
        vector<int>digits;
        
        for (int i=1; i<n; i++){
            digits.push_back(i);
            fact*=i;
        }
        digits.push_back(n);
        
        int tempK = k-1;
        while (true){  
            //Formula for finding currDigit = ((k-1)/fact(n-1)) + 1;
            //fact = (n-1)! (See above Loop executes till n-1)
            currDigit = tempK/fact;
            
            res += (digits[currDigit] + '0');
            digits.erase(digits.begin()+currDigit);
            
            if (digits.size()==0)
                break;

            tempK = tempK%fact;
            fact/=digits.size();
        }
        return res;
    }
};