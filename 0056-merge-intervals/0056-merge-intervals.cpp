class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        vector<int> prev = intervals[0];
        
        for(int i=1; i<intervals.size(); i++){
            
            if(prev[1] >= intervals[i][0]){
                prev[1] = max(prev[1], intervals[i][1]);
            }
            else{
                res.push_back(prev);
                prev = intervals[i];
            }
        }
        res.push_back(prev);
        return res;
    }
};