class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<int> start(n);
        vector<int> end(n);
        
        for(int i=0; i<n; i++){
            start[i] = intervals[i][0]; 
            end[i] = intervals[i][1]; 
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0, cnt = 0, res = 0;
        
        while(i<n){
            
            if(start[i] < end[j]){
                i++;
                cnt++;
            }
            else{
                j++;
                cnt--;
            }
            res = max(res, cnt);
        }
        return res;
    }
};