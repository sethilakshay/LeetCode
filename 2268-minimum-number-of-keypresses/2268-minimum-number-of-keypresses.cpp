class Solution {
public:
    int minimumKeypresses(string s) {
        
        int n = 26, res = 0, cnt = 0;
        vector<int> freq(n, 0);
        
        //Frequency array to keep track of how much each letter has been pressed
        for(char c: s){
            freq[c-'a']++;
        }
        
        //Sorting in descending order to give priority to characters having high frequency
        sort(freq.begin(), freq.end(), [](int& a, int& b){
            return b<a;
        });
        
        //Looping through the frequency array
        for(int i=0; i<26; i++){
            //Increasing count after every 9 iterations
            if(i%9 == 0)
                cnt++;
            
            res += cnt*freq[i];
        }
        
        return res;
    }
};