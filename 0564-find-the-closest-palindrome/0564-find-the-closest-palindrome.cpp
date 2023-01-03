class Solution {
public:
    string nearestPalindromic(string n) {
        // to store all the possible palindromes
        vector<long> posPal;
        
        int digits = n.size();
        
        if(digits == 1){
            return to_string(stol(n)-1);
        }
        
        // Case 1: 1, 11, 101, 1001, 10001, 100001......
        posPal.push_back(pow(10, digits) + 1);
        posPal.push_back(pow(10, digits-1) + 1);
        
        // Case 2: 9, 99, 999, 9999, 99999, 999999......
        posPal.push_back(pow(10, digits) - 1);
        posPal.push_back(pow(10, digits-1) - 1);
        
        // Case 3: Dividing the number at middle and making its 3 palidnromes
        string mid = n.substr(0, (digits+1)/2);
        
        
        for(int i=0; i<3; i++){
            long mid_num = stol(mid);
            mid_num += i - 1;
            
            string prefix = to_string(mid_num);
            string pref_rev = prefix;
            
            if(digits%2 != 0){
                pref_rev = pref_rev.substr(0, pref_rev.size()-1);
            }
            reverse(pref_rev.begin(), pref_rev.end());
            posPal.push_back(stol(prefix + pref_rev));
        }
        
        long diff = LONG_MAX, num = stol(n), res;
        
        for(int i=0; i<posPal.size(); i++){
            
            if(abs(posPal[i] - num) < diff && posPal[i] != num){
                diff = abs(posPal[i] - num);
                res = posPal[i];
            }
            else if(abs(posPal[i] - num) == diff && posPal[i] < res){
                res = posPal[i];
            }
        }
        return to_string(res);
    }
};