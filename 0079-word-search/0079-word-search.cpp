class Solution {
public:
    bool wordChck(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int idx, int r, int c){
        // Base Case
        if(idx == word.size()){
            return true;
        }
        
        // Out of bounds, memoization and word check
        int row = board.size(), col = board[0].size();
        if(!(r>=0 && r<row && c>=0 && c<col && visited[r][c]==false && board[r][c]==word[idx])){
            return false;
        }
        
        visited[r][c] = true;
        bool res;
        
        res = res || wordChck(board, visited, word, idx+1, r+1, c);
        res = res || wordChck(board, visited, word, idx+1, r-1, c);
        res = res || wordChck(board, visited, word, idx+1, r, c+1);
        res = res || wordChck(board, visited, word, idx+1, r, c-1);
        
        visited[r][c] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool> (col, false));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
                if(wordChck(board, visited, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};