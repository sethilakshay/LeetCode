class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> freq(256, 0);
        
        int i = 0, j = 0, cnt = 0, res = 0;
        
        while(i<=j && j<s.size()){
            
            if(freq[s[j]] == 0){
                freq[s[j]]++;
                cnt++;
                j++;
            }
            else{
                freq[s[i]] = 0;
                cnt--;
                i++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};