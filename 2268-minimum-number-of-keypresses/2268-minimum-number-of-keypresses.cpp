class Solution {
public:
    int minimumKeypresses(string s) {
        
        vector<int> freq(26, 0);
        
        for(char c: s){
            freq[c - 'a']++;
        }
        
        // Sorting in Descending order
        sort(freq.begin(), freq.end(), [](int& a, int& b){
            return b<a;
        });
        
        int res = 0, cnt = 0;
        
        for(int i=0; i<26; i++){
            
            if(freq[i] == 0){
                break;
            }
            
            if(i%9 == 0){
                cnt++;
            }
            
            res += cnt*freq[i];
        }
        return res;
    }
};