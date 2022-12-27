class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, int& cnt_sq, int& res, int steps){
        int row = grid.size(), col = grid[0].size();
        // Base Case
        if(!(r>=0 && r<row && c>=0 && c<col && grid[r][c] != -1)){
            return;
        }
        
        if(grid[r][c] == 2){
            if(steps == cnt_sq)
                res++;
            return;
        }
        
        
        grid[r][c] = -1;
        
        dfs(r+1, c, grid, cnt_sq, res, steps+1);
        dfs(r-1, c, grid, cnt_sq, res, steps+1);
        dfs(r, c+1, grid, cnt_sq, res, steps+1);
        dfs(r, c-1, grid, cnt_sq, res, steps+1);
           
        grid[r][c] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        
        int start_r, start_c, cnt_sq = 1;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0){
                    cnt_sq++;
                }
                if(grid[i][j] == 1){
                    start_r = i;
                    start_c = j;
                }
            }
        }
        
        int res = 0, steps = 0;
        dfs(start_r, start_c, grid, cnt_sq, res, steps);
        return res;
    }
};