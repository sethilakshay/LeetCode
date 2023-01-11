class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size(), fresh = 0;
        queue<pair<int, int>> rottingQ;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    rottingQ.push({i, j});
                }
            }
        }
        
        if(fresh == 0){
            return 0;
        }
        
        int res = -1, num_fresh = 0;
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!rottingQ.empty()){
            int n = rottingQ.size();
            
            for(int i=0; i<n; i++){
                int curr_r = rottingQ.front().first;
                int curr_c = rottingQ.front().second;
                rottingQ.pop();
                
                for(int k=0; k<directions.size(); k++){
                    int mod_r = curr_r + directions[k].first;
                    int mod_c = curr_c + directions[k].second;
                    
                    if(mod_r>=0 && mod_r<row && mod_c>=0 && mod_c<col && grid[mod_r][mod_c]==1){
                        grid[mod_r][mod_c] = 2;
                        rottingQ.push({mod_r, mod_c});
                        num_fresh++;
                    }
                }
            }
            res++;
        }
        
        if(num_fresh != fresh){
            return -1;
        }
        
        return res;
    }
};