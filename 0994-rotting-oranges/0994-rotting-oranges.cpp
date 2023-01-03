class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int fresh = 0, res = -1;
        queue<pair<int, int>> q;
        int row = grid.size(), col = grid[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        int curr = 0;
        vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while(!q.empty()){
            
            int n = q.size();
            res++;
            for(int i=0; i<n; i++){
                int c_row = q.front().first;
                int c_col = q.front().second;
                q.pop();
                
                for(int j=0; j<directions.size(); j++){
                    int m_row = c_row + directions[j].first;
                    int m_col = c_col + directions[j].second;
                    
                    if(m_row>=0 && m_row<row && m_col>=0 && m_col<col && grid[m_row][m_col] == 1){
                        grid[m_row][m_col] = 2;
                        q.push({m_row, m_col});
                        curr++;
                    }
                }
            }
        }
        
        if(fresh == 0){
            return 0;
        }
        
        if(curr != fresh){
            return -1;
        }
        
        return res;
        
    }
};