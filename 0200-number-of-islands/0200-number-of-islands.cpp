class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid){
        int row = grid.size(), col = grid[0].size();
        
        if(!(r>=0 && r<row && c>=0 && c<col && visited[r][c] == false && grid[r][c] == '1')){
            return;
        }
        
        visited[r][c] = true;
        
        dfs(r+1, c, visited, grid);
        dfs(r-1, c, visited, grid);
        dfs(r, c+1, visited, grid);
        dfs(r, c-1, visited, grid);
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for(int i=0; i<row; i++){
            
            for(int j=0; j<col; j++){
                
                if(grid[i][j] == '1' && visited[i][j] == false){
                    res++;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return res;
    }
};