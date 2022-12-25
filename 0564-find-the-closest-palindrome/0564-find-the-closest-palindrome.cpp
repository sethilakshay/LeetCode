class Solution {
public:
    string nearestPalindromic(string n) {
        int digits = n.size();
        
        if(digits==1)
            return to_string(stoi(n)-1);
        
        vector<long> res;
        res.push_back(pow(10, digits)+1);  //Case 1: 1, 11, 101, 1001, 10001.....
        res.push_back(pow(10, digits-1)+1); //Case 1: 1, 11, 101, 1001, 10001.....
        
        res.push_back(pow(10, digits)-1);  //Case 2: 9, 99, 999, 9999.......
        res.push_back(pow(10, digits-1)-1);  //Case 2: 9, 99, 999, 9999.......
        
        // Case 3: Dividing the prefix at mid-point and making that a palindrome
        // 3 Cases: to find mid-1, mid and mid+1 palindromes
        int mid = (digits+1)/2;
        long prefix = stol(n.substr(0, mid));
        
        for(int i=0; i<3; i++){
            string pref = to_string(prefix-1+i);
            string pref_rev = pref; // Normal case for even digits
            
            // In case if we have an odd number, then other half will have 1 less digit
            if(digits%2 != 0)
                pref_rev = pref_rev.substr(0, pref_rev.size()-1);

            reverse(pref_rev.begin(), pref_rev.end());
            string temp_res = pref + pref_rev;
            
            res.push_back(stol(temp_res));
        }
        
        long diff = LONG_MAX, num = stol(n), ans = 0;
        
        for(int i=0; i<7; i++){ 
            
            if (abs(res[i]-num) < diff && res[i]!=num){
                diff = abs(res[i]-num);
                ans = res[i];
            }
            
            else if((abs(res[i]-num) == diff) && (res[i]<ans)){
                ans = res[i];
            }
        }
        return to_string(ans);
    }
};