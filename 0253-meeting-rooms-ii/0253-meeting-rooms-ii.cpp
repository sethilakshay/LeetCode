class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        vector<int> start;
        vector<int> end;
        
        for(int i = 0; i<intervals.size(); i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int res = 0, cnt = 0, i = 0, j = 0;
        
        while(i<intervals.size() && j<=i){
            
            if(start[i] < end[j]){
                cnt++;
                i++;
            } else{
                cnt--;
                j++;
            }
            
            res = max(cnt, res);
        }
        
        return res;
    }
};