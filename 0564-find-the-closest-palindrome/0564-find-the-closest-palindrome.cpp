class Solution {
public:
    string nearestPalindromic(string n) {
        int digits = n.size();
        
        if(digits == 1){
            return to_string(stoi(n)-1);
        }
        
        vector<long> posPal;
        // Case 1: 1, 11, 101, 1001, 10001.....
        posPal.push_back(pow(10, digits) + 1);
        posPal.push_back(pow(10, digits-1) + 1);
        
        // Case 2: 9, 99, 999, 9999, 99999......
        posPal.push_back(pow(10, digits) - 1);
        posPal.push_back(pow(10, digits-1) - 1);
        
        // Case 3: Taking middle number and making its 3 palindromes
        
        string mid = n.substr(0, (digits+1)/2);
        long midNum = stol(mid);
        
        for(int i=0; i<3; i++){
            string prefix = to_string(midNum - 1 + i);
            string pref_rev = prefix;
            
            if(digits%2 != 0){
                pref_rev = pref_rev.substr(0, pref_rev.size()-1);
            }
            
            reverse(pref_rev.begin(), pref_rev.end());
            posPal.push_back(stol(prefix + pref_rev));
        }
        
        long diff = LONG_MAX, res = 0, num = stol(n);
        
        for(int i=0; i<posPal.size(); i++){
            
            if(abs(posPal[i] - num) < diff && posPal[i] != num){
                diff = abs(posPal[i] - num);
                res = posPal[i];
            }
            else if(abs(posPal[i] - num) == diff && posPal[i] != num && posPal[i] < res){
                res = posPal[i];
            }
        }
        return to_string(res);
    }
};