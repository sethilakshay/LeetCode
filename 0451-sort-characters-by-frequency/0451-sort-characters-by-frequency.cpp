class Solution {
public:
    string frequencySort(string s) {
        
        vector<int> freq(256, 0);
        
        for(char c: s){
            freq[c - '0']++;
        }
        
        sort(s.begin(), s.end(), [freq](char& a, char& b){
            if(freq[a - '0'] != freq[b - '0'])
                return freq[a - '0'] > freq[b - '0'];
            
            return b>a;
        });
        return s;
    }
};