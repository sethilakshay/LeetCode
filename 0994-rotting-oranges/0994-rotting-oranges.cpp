class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, row = grid.size(), col = grid[0].size(), res = -1, cnt_fresh = 0;
        queue <pair<int, int>> q;
        
        for(int i=0; i<row; i++){
            
            for(int j=0; j<col; j++){
                
                if(grid[i][j] == 1)
                    fresh++;
                
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            
            int n = q.size();
            res++;
            
            while(n--){
                int new_r = q.front().first;
                int new_c = q.front().second;
                q.pop();

                for(int i=0; i<dirs.size(); i++){
                    int mod_r = new_r + dirs[i].first;
                    int mod_c = new_c + dirs[i].second;

                    if(0<=mod_r && mod_r<row && 0<=mod_c && mod_c<col){
                        if(grid[mod_r][mod_c] == 1){
                            grid[mod_r][mod_c] = 2;
                            cnt_fresh++;
                            q.push({mod_r, mod_c});
                        }
                    }
                }
            }
        }
        if (cnt_fresh != fresh)
            return -1;
        
        if(fresh==0)
            return 0;
        
        return res;
    }
};