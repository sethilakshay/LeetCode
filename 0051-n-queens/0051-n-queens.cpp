class Solution {
public:
    void n_queen(int row, int n, vector<string>& curr, vector<vector<string>>& res, vector<bool>& col_chck, vector<bool>& pDiag_chck, vector<bool>& sDiag_chck){
        
        if(row == n){
            res.push_back(curr);
            return;
        }
        
        for(int col=0; col<n; col++){
            
            if(col_chck[col] || pDiag_chck[col-row+n] || sDiag_chck[row+col]){
                continue;
            }
            
            col_chck[col] = pDiag_chck[col-row+n] = sDiag_chck[row+col] = true;
            curr[row][col] = 'Q';
            
            n_queen(row+1, n, curr, res, col_chck, pDiag_chck, sDiag_chck);
            
            col_chck[col] = pDiag_chck[col-row+n] = sDiag_chck[row+col] = false;
            curr[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<bool> col_chck(n, false);
        vector<bool> pDiag_chck(2*n-1, false);
        vector<bool> sDiag_chck(2*n-1, false);
        
        vector<vector<string>> res;
        vector<string> curr(n, string(n, '.'));
        
        n_queen(0, n, curr, res, col_chck, pDiag_chck, sDiag_chck);
        return res;
    }
};