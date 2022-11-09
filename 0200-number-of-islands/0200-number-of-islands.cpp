class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visited){
        
        visited[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        
        vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = grid.size(), cols = grid[0].size(), curr_r, curr_c, mod_r, mod_c;
        
        while(!q.empty()){
            
            curr_r = q.front().first;
            curr_c = q.front().second;
            q.pop();
            
            for(int i=0; i<dirs.size(); i++){
                mod_r = curr_r + dirs[i].first;
                mod_c = curr_c + dirs[i].second;
                
                if((0<=mod_r && mod_r<rows) && (0<=mod_c && mod_c<cols)){
                    
                    if(grid[mod_r][mod_c] == '1' && visited[mod_r][mod_c] == 0){
                        visited[mod_r][mod_c] = 1;
                        q.push({mod_r, mod_c});
                    }
                } 
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size(), cols = grid[0].size(), islands = 0;
        
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        for(int i=0; i<rows; i++){
            
            for(int j=0; j<cols; j++){
                
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    bfs(i, j, grid, visited);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};