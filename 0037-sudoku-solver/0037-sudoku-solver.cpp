class Solution {
public:
    void buildBoard(int row, int col, vector<vector<char>>& board, vector<vector<char>>& res, vector<vector<bool>>& row_chck, vector<vector<bool>>& col_chck, vector<vector<bool>>& subsq_chck){
        // Base Case
        if(row == 9){
            res = board;
            return;
        }
        
        if(board[row][col] != '.'){
            if(col<8){
                buildBoard(row, col+1, board, res, row_chck, col_chck, subsq_chck);
            }
            else{
                buildBoard(row+1, 0, board, res, row_chck, col_chck, subsq_chck);
            }
            return;
        }
        
        // Recursive Case
        for(int i=0; i<9; i++){
            
            if(row_chck[row][i] || col_chck[col][i] || subsq_chck[((row/3)*3) + (col/3)][i]){
                continue;
            }
            
            row_chck[row][i] = true;
            col_chck[col][i] = true;
            subsq_chck[((row/3)*3) + (col/3)][i] = true;
            board[row][col] = (i + 1) + '0';
            
            buildBoard(row, col+1, board, res, row_chck, col_chck, subsq_chck);
            
            row_chck[row][i] = false;
            col_chck[col][i] = false;
            subsq_chck[((row/3)*3) + (col/3)][i] = false;
            board[row][col] = '.';
        }
        return;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        int n = board.size();
        
        vector<vector<bool>> row_chck(n, vector<bool> (n, false));
        vector<vector<bool>> col_chck(n, vector<bool> (n, false));
        vector<vector<bool>> subsq_chck(n, vector<bool> (n, false));
        
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(board[row][col] != '.'){
                    row_chck[row][board[row][col] - '1'] = true;
                    col_chck[col][board[row][col] - '1'] = true;
                    subsq_chck[((row/3)*3) + (col/3)][board[row][col] - '1'] = true;
                }
            }
        }
        vector<vector<char>> res;
        buildBoard(0, 0, board, res, row_chck, col_chck, subsq_chck);
        board = res;
    }
};