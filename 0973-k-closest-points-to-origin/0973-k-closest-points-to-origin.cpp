class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
            
        vector<vector<int>> res(k);
        
        for(int i=0; i<k; i++){
            res[i] = points[i];
        }
        
        return res;
    }
};