class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        vector<pair<float, vector<int>>> dist(n);
        for(int i=0; i<n; i++){
            dist[i] = make_pair(pow(pow(points[i][0], 2) + pow(points[i][1], 2), 0.5), points[i]);
        }
        
        sort(dist.begin(), dist.end(), [](pair<float, vector<int>>& a, pair<float, vector<int>>& b){
            return a.first<b.first;
        });
            
        vector<vector<int>> res(k);
        
        for(int i=0; i<k; i++){
            res[i] = dist[i].second;
        }
        
        return res;
    }
};