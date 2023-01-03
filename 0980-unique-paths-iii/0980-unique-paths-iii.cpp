class Solution {
public:
    void findPath(int r, int c, int& em_sq, int curr_sq, vector<vector<int>>& grid, int& res){

        if(!(r>= 0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] != -1)){
            return;
        }
        
        if(grid[r][c] == 2){
            if(em_sq == curr_sq)
                res++;
            return;
        }
        
        grid[r][c] = -1;
        
        findPath(r+1, c, em_sq, curr_sq+1, grid, res);
        findPath(r-1, c, em_sq, curr_sq+1, grid, res);
        findPath(r, c+1, em_sq, curr_sq+1, grid, res);
        findPath(r, c-1, em_sq, curr_sq+1, grid, res);
        
        grid[r][c] = 0;
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int em_sq = 0;
        pair<int, int> start;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    em_sq++;
                }
                else if(grid[i][j] == 1){
                    start = make_pair(i, j);
                    em_sq++;
                }
            }
        }
        
        int res = 0, curr_sq = 0;
        
        findPath(start.first, start.second, em_sq, curr_sq, grid, res);
        return res;
    }
};