class Solution {
public:
    int minimumKeypresses(string s) {
        
        int n = 26, res = 0;
        vector<int> freq(n, 0);
        
        for(char c: s){
            freq[c-'a']++;
        }
        
        sort(freq.begin(), freq.end(), [](int& a, int& b){
            return b<a;
        });
        
        int cnt = 8;
        
        for(int i=0; i<26; i++){
            
            if(freq[i] > 0){
                cnt++;
            }
            res += (cnt/9)*freq[i];
        }
        
        return res;
    }
};