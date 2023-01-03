class Solution {
public:
    void sudoku(int row, int col, vector<vector<char>>& res, vector<vector<char>>& board, vector<vector<bool>>& row_chck, vector<vector<bool>>& col_chck, vector<vector<bool>>& subsq_chck){
        
        if(row == 9){
            res = board;
            return;
        }
        
        if(board[row][col] != '.'){
            if(col < 8){
                sudoku(row, col+1, res, board, row_chck, col_chck, subsq_chck);
            }
            else{
                sudoku(row+1, 0, res, board, row_chck, col_chck, subsq_chck);
            }
            return;
        }
        
        for(int i=0; i<9; i++){
            
            if(row_chck[row][i] || col_chck[col][i] || subsq_chck[(row/3)*3 + col/3][i]){
                continue;
            }
            
            row_chck[row][i] = col_chck[col][i] = subsq_chck[((row/3)*3) + col/3][i] = true;
            board[row][col] = i + '1';
            
            if(col < 8){
                sudoku(row, col+1, res, board, row_chck, col_chck, subsq_chck);
            }
            else{
                sudoku(row+1, 0, res, board, row_chck, col_chck, subsq_chck);
            }
            
            row_chck[row][i] = col_chck[col][i] = subsq_chck[((row/3)*3) + col/3][i] = false;
            board[row][col] = '.';
        }
        return;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> res;
        
        vector<vector<bool>> row_chck(9, vector<bool>(9, false));
        vector<vector<bool>> col_chck(9, vector<bool>(9, false));
        vector<vector<bool>> subsq_chck(9, vector<bool>(9, false));
        
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                
                if(board[row][col] != '.'){
                    row_chck[row][board[row][col] - '1'] = true;
                    col_chck[col][board[row][col] - '1'] = true;
                    subsq_chck[((row/3)*3) + (col/3)][board[row][col] - '1'] = true;
                }
            }
        }
        
        sudoku(0, 0, res, board, row_chck, col_chck, subsq_chck);
        board = res;
    }
};