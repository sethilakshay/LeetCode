class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int row = grid.size(), col = grid[0].size();
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
        
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        
        while(!q.empty()){
            
            int mod_r = q.front().first;
            int mod_c = q.front().second;
            q.pop();
            
            for(int i=0; i<dirs.size(); i++){
                int new_r = mod_r + dirs[i].first;
                int new_c = mod_c + dirs[i].second;
                
                if(0<=new_r && new_r<row && 0<=new_c && new_c<col){
                    
                    if(grid[new_r][new_c] == '1' && visited[new_r][new_c] == false){
                        visited[new_r][new_c] = true;
                        q.push({new_r, new_c});
                    }
                }
                
            }
            
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for(int i=0; i<row; i++){
            
            for(int j=0; j<col; j++){
                
                if(grid[i][j] == '1' && visited[i][j] == false){
                    
                    bfs(i, j, grid, visited);
                    res++;
                }
            }
        }
        return res;
    }
};