class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case
        if(t == "" || s.size() == 0){
            return "";
        }
        
        unordered_map<char, int> tMap;
        unordered_map<char, int> sMap;
        
        for(char c: t){
            tMap[c]++;
        }

        int need = tMap.size(), have = 0;
        int i = 0, j = 0, resLen = INT_MAX, start = -1;
        
        while(j < s.size()){

            if(tMap.find(s[j]) != tMap.end()){
                sMap[s[j]]++;
                
                if(tMap[s[j]] == sMap[s[j]]){
                    have++;
                }
            }
            
            while(have == need && i <= j){
                
                if(resLen > j-i+1){
                    resLen = j-i+1;
                    start = i;
                }
                
                if(tMap.find(s[i]) != tMap.end()){
                    sMap[s[i]]--;
                    
                    if(sMap[s[i]] < tMap[s[i]]){
                        have--;
                    }
                }
                i++;
            }
            j++;
        }

        // Important Time Optimization else TLE
        return start != -1 ? s.substr(start, resLen) : "";
    }
};