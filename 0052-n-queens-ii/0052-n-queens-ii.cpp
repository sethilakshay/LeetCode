class Solution {
public:
    void nQueen(int row, int& n, vector<bool>& colVis, vector<bool>& pDiag, vector<bool>& sDiag, int& res){
        // Base Case
        if(row == n){
            res++;
            return;
        }
        
        for(int col=0; col<n; col++){
            
            if(colVis[col] || pDiag[col-row+n] || sDiag[row+col]){
                continue;
            }
            
            colVis[col] = true;
            pDiag[col-row+n] = true;
            sDiag[row+col] = true;
            
            nQueen(row+1, n, colVis, pDiag, sDiag, res);
            
            colVis[col] = false;
            pDiag[col-row+n] = false;
            sDiag[row+col] = false;
        }
    }
    
    int totalNQueens(int n) {
        vector<bool> colVis(n, false);
        vector<bool> pDiag(2*n-1, false);
        vector<bool> sDiag(2*n-1, false);
        
        int res = 0;
        
        nQueen(0, n, colVis, pDiag, sDiag, res);
        return res;
    }
};