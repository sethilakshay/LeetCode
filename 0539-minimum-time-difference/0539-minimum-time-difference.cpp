class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> time (1440, 0);
        int mins, hrs, tot_time;
        
        for(string curr_time: timePoints){
            
            hrs = stoi(curr_time.substr(0, 2))*60;
            mins = stoi(curr_time.substr(3, 2));
            
            tot_time = hrs + mins;
            
            if(time[tot_time] != 0){
                return 0;
            }
            
            time[tot_time]++;
        }
        
        
        
        int first = INT_MAX, last = INT_MIN, res;
        int prev, min_T = INT_MAX;
        
        for(int i=0; i<1440; i++){
            
            if(time[i] != 0){
                
                if(first != INT_MAX){
                    min_T = min(min_T, i - prev);
                    
                }
            
                first = min(first, i);
                last = max(last, i);
                prev = i;
            }
        }
        res = min(min_T, 1440-last+first);
        return res;
    }
};