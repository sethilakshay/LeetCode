class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visited){
        
        visited[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        
        int row, col, mod_r, mod_c;
        int n = grid.size(), m = grid[0].size();
        
        vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int mod_r = row + directions[i].first;
                int mod_c = col + directions[i].second;
                
                if((0<=mod_r && mod_r<n) && (0<=mod_c && mod_c<m)){
                    
                    if((grid[mod_r][mod_c] == '1') && (visited[mod_r][mod_c] == 0)){
                        visited[mod_r][mod_c] = 1;
                        q.push({mod_r, mod_c});
                    }
                    
                }
                
            }
            
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.size() == 0)
            return 0;

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