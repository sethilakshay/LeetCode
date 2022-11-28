class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        
        int row = grid.size(), col = grid[0].size();
        
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;
        
        q.push({r,c});
        visited[r][c] = true;
        
        while(!q.empty()){
            pair curr = q.front();
            q.pop();
            
            for(int i=0; i<dirs.size(); i++){
                int mod_r = curr.first + dirs[i].first;
                int mod_c = curr.second + dirs[i].second;
                
                if(mod_r >= 0 && mod_r < row && mod_c >= 0 && mod_c < col){
                    if(grid[mod_r][mod_c] == '1' && visited[mod_r][mod_c] == false){
                        
                        visited[mod_r][mod_c] = true;
                        q.push({mod_r, mod_c});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size(), col = grid[0].size(), res = 0;
        
        vector<vector<bool>> visited(row, vector<bool> (col, false));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
                if(grid[i][j] == '1' && visited[i][j] == false){
                    res++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return res;
    }
};