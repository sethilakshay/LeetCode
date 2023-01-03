class Solution {
public:
    string nearestPalindromic(string n) {
        
        vector<long> res;
        int digits = n.size();
        
        if(digits == 1){
            return to_string(stol(n)-1);
        }
        
        //Case 1: 1, 11, 101, 1001, 10001...
        res.push_back(pow(10, digits) + 1);
        res.push_back(pow(10, digits-1) + 1);
        
        //Case 2: 9, 99, 999, 9999, 99999...
        res.push_back(pow(10, digits) - 1);
        res.push_back(pow(10, digits-1) - 1);
        
        //Case 3
        string mid = n.substr(0, (digits+1)/2);
        
        for(long i=0; i<3; i++){
            long mid_num = stol(mid);
            mid_num += i - 1;
            
            string prefix = to_string(mid_num);
            string pref_rev = prefix;
            
            if(digits%2 != 0){
                pref_rev = pref_rev.substr(0, pref_rev.size()-1);
            }
            reverse(pref_rev.begin(), pref_rev.end());
            res.push_back(stol(prefix + pref_rev));
        }
        
        long diff = LONG_MAX, ans, num = stol(n);
        
        for(int i=0; i<res.size(); i++){
            
            if(abs(res[i] - num) < diff && res[i] != num){
                diff = abs(res[i] - num);
                ans = res[i];
            }
            else if(abs(res[i] - num) == diff && res[i] < ans){
                ans = res[i];
            }
        }
        return to_string(ans);
    }
};