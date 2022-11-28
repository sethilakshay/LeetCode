class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int n = intervals.size(), i = 0, j = 0, res = 0, cnt = 0;
        
        vector<int> start(n);
        vector<int> end(n);
        
        for(int i=0; i<n; i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        while(i<n && j<=i){
            if(start[i] < end[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};