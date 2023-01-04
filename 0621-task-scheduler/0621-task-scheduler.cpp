class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26, 0);
        int maxF = 0, cnt = 0, n1 = tasks.size();
        
        for(int i=0; i<n1; i++){
            freq[tasks[i] - 'A']++;
            maxF = max(maxF, freq[tasks[i] - 'A']);
        }
        
        for(int i=0; i<26; i++){
            if(maxF == freq[i]){
                cnt++;
            }
        }
        
        int rem_cnt = n1 - (maxF*cnt);
        int rem_gaps = (n-cnt+1)*(maxF - 1);
        
        if(rem_cnt >= rem_gaps){
            return n1;
        }
        
        return rem_gaps + maxF*cnt;
    }
};