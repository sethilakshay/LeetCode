class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int r, int c, int idx){
        int row = board.size(), col = board[0].size();
        if(idx == word.size()){
            return true;
        }
        
        if(!(r>=0 && r<row && c>=0 && c<col && visited[r][c]==false && board[r][c]==word[idx])){
            return false;
        }

        visited[r][c] = true;
        bool res;
        
        res = res || dfs(board, word, visited, r+1, c, idx+1);
        res = res || dfs(board, word, visited, r-1, c, idx+1);
        res = res || dfs(board, word, visited, r, c+1, idx+1);
        res = res || dfs(board, word, visited, r, c-1, idx+1);
        
        visited[r][c] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool> (col, false));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
                if(dfs(board, word, visited, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};