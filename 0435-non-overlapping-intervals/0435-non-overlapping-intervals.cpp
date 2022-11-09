bool compare (vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if (intervals.size()==1) return 0;
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int end = intervals[0][1];
        int cnt = 0;
        
        for (int i=1; i<intervals.size(); i++){
        
            if (intervals[i][0]<end){
                cnt++;
            }
            else  end = intervals[i][1];
        }
        return cnt;
    }
};