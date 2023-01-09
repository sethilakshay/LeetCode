class Solution {
public:
    string frequencySort(string s) {
        
        vector<int> freq(256, 0);
        
        for(char c: s){
            freq[c]++;
        }
        
        sort(s.begin(), s.end(), [freq](char& a, char& b){
            if(freq[a] != freq[b])
                return freq[a] > freq[b];
            
            return b>a;
        });
        return s;
    }
};