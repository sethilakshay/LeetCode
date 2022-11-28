class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        vector<int> start (n);
        vector<int> end (n); 
        vector<vector<int>> res;
        
        for(int i=0; i<n; i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int st = start[0];
        int en = end[0];

        for(int i=1; i<n; i++){
            
            if(en < start[i]){
                res.push_back({st, en});
                
                st = start[i];
            }
            
            en = end[i];
        }
        
        res.push_back({st, en});
        return res;
    }
};