class Solution {
public:
    void bfs(pair<int, int>& pos, vector<vector<int>>& grid, vector<pair<int, int>>& rotten){
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        int row = grid.size(), col = grid[0].size(), temp_r, temp_c;
        
        for(int i=0; i<directions.size(); i++){
            
            temp_r = pos.first + directions[i].first;
            temp_c = pos.second + directions[i].second;
            
            if(temp_r>=0 && temp_r<row && temp_c>=0 && temp_c<col && grid[temp_r][temp_c] == 1){
                grid[temp_r][temp_c] = 2;
                rotten.push_back({temp_r, temp_c});
            }
            else{
                continue;
            }
        }
    }
        
        
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        int fresh = 0, res = 0;
        
        vector<pair<int, int>> rotten;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    rotten.push_back({i, j});
                }
            }
        }
        
        if(fresh==0){
            return 0;
        }
        
        bool chck = true;
        while(chck && fresh > 0){
            
            vector<pair<int, int>> rotten_temp;
            
            for(int i=0; i<rotten.size(); i++){
                bfs(rotten[i], grid, rotten_temp);
            }
            res++;
            
            if(rotten_temp.size() == 0){
                chck = false;
            }
            rotten = rotten_temp;
            fresh -= rotten.size();
        }
        
        return fresh != 0 ? -1 : res;
    }
};