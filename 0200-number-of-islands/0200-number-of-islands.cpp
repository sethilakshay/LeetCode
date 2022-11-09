class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& visited){
        
        if(r<0 || r>=grid.size() ||c<0 || c>=grid[0].size() || grid[r][c] == '0' || visited[r][c] == 1){
            return;
        }
        
        visited[r][c] = 1;
        dfs(r+1, c, grid, visited);
        dfs(r-1, c, grid, visited);
        dfs(r, c+1, grid, visited);
        dfs(r, c-1, grid, visited);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.size() == 0)
            return 0;

        int rows = grid.size(), cols = grid[0].size(), islands = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        for(int i=0; i<rows; i++){
            
            for(int j=0; j<cols; j++){
                
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    dfs(i, j, grid, visited);
                    islands += 1;
                }
            }
        }
        
        return islands;
    }
};