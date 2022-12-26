class Solution {
public:
    void sudoku(int row, int col, int& n, vector<vector<bool>>& rowChck, vector<vector<bool>>& colChck, vector<vector<bool>>& subSqChck, vector<vector<char>>& res, vector<vector<char>>& board){
        // Base Case 1
        if(row == n){
            res = board;
            return;
        }
        
        // Base Case 2
        if(board[row][col] != '.'){
            if(col < n-1){
                sudoku(row, col+1, n, rowChck, colChck, subSqChck, res, board);
            }
            else{
                sudoku(row+1, 0, n, rowChck, colChck, subSqChck, res, board);
            }
            return;
        }
        
        // Recursive case
        // Iterating from 0 to 8 to fill in the character
        for(int i=0; i<n; i++){
            if(rowChck[row][i] || colChck[col][i] || subSqChck[((row/3)*3)+(col/3)][i]){
                continue;
            }
                
            rowChck[row][i] = colChck[col][i] = subSqChck[((row/3)*3)+(col/3)][i] = true;
            board[row][col] = char(i+'1');

            if(col < n-1){
                sudoku(row, col+1, n, rowChck, colChck, subSqChck, res, board);
            }
            else{
                sudoku(row+1, 0, n, rowChck, colChck, subSqChck, res, board);
            }

            rowChck[row][i] = colChck[col][i] = subSqChck[((row/3)*3)+(col/3)][i] = false;
            board[row][col] = '.';
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        int n = 9;
        
        vector<vector<bool>> rowChck(n, vector<bool> (n, false));
        vector<vector<bool>> colChck(n, vector<bool> (n, false));
        vector<vector<bool>> subSqChck(n, vector<bool> (n, false));
        vector<vector<char>> res;
        
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(board[row][col] != '.'){
                    rowChck[row][board[row][col] - '1'] = true;
                    colChck[col][board[row][col] - '1'] = true;
                    subSqChck[((row/3)*3) + (col/3)][board[row][col] - '1'] = true;
                }
            }
        }
        
        sudoku(0, 0, n, rowChck, colChck, subSqChck, res, board);
        board = res;
    }
};