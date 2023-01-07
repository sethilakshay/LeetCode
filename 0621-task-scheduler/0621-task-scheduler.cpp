class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26, 0);
        int max_freq = 0;
        
        for(char c: tasks){
            freq[c - 'A']++;
            max_freq = max(max_freq, freq[c - 'A']);
        }
        
        int cnt_max = 0;
        
        for(int i=0; i<26; i++){
            if(max_freq == freq[i]){
                cnt_max++;
            }
        }
        
        int rem_cnt = tasks.size() - (max_freq*cnt_max);
        int rem_gaps =  (n+1-cnt_max)*(max_freq-1);
        
        if(rem_cnt < rem_gaps){
            return rem_gaps + (max_freq*cnt_max);
        }
        
        return tasks.size();
    }
};