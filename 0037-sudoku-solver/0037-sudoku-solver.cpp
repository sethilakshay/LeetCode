class Solution {
public:
    void solve(int row, int col, vector<vector<bool>>& row_chck, vector<vector<bool>>& col_chck, vector<vector<bool>>& subsq_chck, vector<vector<char>>& board, vector<vector<char>>& res){
        // Base Case
        if(row == 9){
            res = board;
            return;
        }
        
        if(board[row][col] != '.'){
            if(col < 8){
                solve(row, col+1, row_chck, col_chck, subsq_chck, board, res);
            }
            else{
                solve(row+1, 0, row_chck, col_chck, subsq_chck, board, res);
            }
            return;
        }
        
        // Recurisve Case
        for(int i=0; i<9; i++){
            if(row_chck[row][i] || col_chck[col][i] || subsq_chck[(row/3)*3 + col/3][i]){
                continue;
            }
            
            row_chck[row][i] = col_chck[col][i] = subsq_chck[(row/3)*3 + col/3][i] = true;
            board[row][col] = i + '1';
            
            if(col < 8){
                solve(row, col+1, row_chck, col_chck, subsq_chck, board, res);
            }
            else{
                solve(row+1, 0, row_chck, col_chck, subsq_chck, board, res);
            }
            
            row_chck[row][i] = col_chck[col][i] = subsq_chck[(row/3)*3 + col/3][i] = false;
            board[row][col] = '.';   
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> row_chck(9, vector<bool>(9, false));
        vector<vector<bool>> col_chck(9, vector<bool>(9, false));
        vector<vector<bool>> subsq_chck(9, vector<bool>(9, false));
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] != '.'){
                    row_chck[i][board[i][j] - '1'] = true;
                    col_chck[j][board[i][j] - '1'] = true;
                    subsq_chck[(i/3)*3 + j/3][board[i][j] - '1'] = true;
                }
            }
        }
        
        vector<vector<char>> res;
        
        solve(0, 0, row_chck, col_chck, subsq_chck, board, res);
        board = res;
        
    }
};