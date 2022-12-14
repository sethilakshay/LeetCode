class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), res = 0;
        
        vector<int> freq(26, 0);
        
        for(int i = 0; i<n; i++){
            
            if(freq[s[i]-'a'] != 0){
            
                for(int k=0; k<26; k++)
                    freq[k] = 0;
                
                res++;
            }
            
            freq[s[i]-'a'] = 1;
            
        }
        return res+1;
        
    }
};