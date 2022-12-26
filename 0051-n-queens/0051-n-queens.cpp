class Solution {
public:
    void queen(int row, int& n, vector<bool>& colVis, vector<bool>& pDiag, vector<bool>& sDiag, vector<vector<string>>& res, vector<string>& curr){
        // Base Case
        if(row == n){
            res.push_back(curr);
            return;
        }
        
        for(int col = 0; col<n; col++){
            
            if(colVis[col] || pDiag[col-row+n] || sDiag[row+col]){
                continue;
            }
            
            curr[row][col] = 'Q';
            colVis[col] = pDiag[col-row+n] = sDiag[row+col] = true;
            
            queen(row+1, n, colVis, pDiag, sDiag, res, curr);
            
            curr[row][col] = '.';
            colVis[col] = pDiag[col-row+n] = sDiag[row+col] = false;
        }   
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<bool> colVis(n, false);
        vector<bool> pDiag(2*n-1, false);
        vector<bool> sDiag(2*n-1, false);
        
        vector<vector<string>> res;
        vector<string> curr(n, string(n, '.'));
        
        queen(0, n, colVis, pDiag, sDiag, res, curr);
        return res;
    }
};