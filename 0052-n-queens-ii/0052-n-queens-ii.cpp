class Solution {
public:
    void nQueen(int row, int& n, vector<bool>& colVis, vector<bool>& pDiag, vector<bool>& sDiag, vector<string>& curr, vector<vector<string>>& res){
        // Base Case
        if(row == n){
            res.push_back(curr);
            return;
        }
        
        for(int col=0; col<n; col++){
            
            if(colVis[col] || pDiag[col-row+n] || sDiag[row+col]){
                continue;
            }
            
            curr[row][col] = 'Q';
            colVis[col] = true;
            pDiag[col-row+n] = true;
            sDiag[row+col] = true;
            
            nQueen(row+1, n, colVis, pDiag, sDiag, curr, res);
            
            curr[row][col] = '.';
            colVis[col] = false;
            pDiag[col-row+n] = false;
            sDiag[row+col] = false;
        }
    }
    
    int totalNQueens(int n) {
        vector<bool> colVis(n, false);
        vector<bool> pDiag(2*n-1, false);
        vector<bool> sDiag(2*n-1, false);
        
        vector<vector<string>> res;
        vector<string> curr (n, string(n, '.'));
        
        nQueen(0, n, colVis, pDiag, sDiag, curr, res);
        return res.size();
    }
};