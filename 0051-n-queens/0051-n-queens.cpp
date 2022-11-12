class Solution {
public:
    void n_queen(int& n, int row, vector<vector<string>>& res, vector<string>& currSet, vector<bool>& col_visit, vector<bool>& pdiag_visit, vector<bool>& scdiag_visit){
        
        if(row==n){
            res.push_back(currSet);
            return;
        }
        
        for(int col = 0; col<n; col++){
            
            if(col_visit[col] || pdiag_visit[col-row+n] || scdiag_visit[row+col])
                continue;
            
            currSet[row][col] = 'Q';
            col_visit[col] = pdiag_visit[col-row+n] = scdiag_visit[row+col] = true;
            
            n_queen(n, row+1, res, currSet, col_visit, pdiag_visit, scdiag_visit);
            
            currSet[row][col] = '.';
            col_visit[col] = pdiag_visit[col-row+n] = scdiag_visit[row+col] = false;
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> currSet (n, string(n, '.'));
        
        vector<bool> col_visit(n, false);
        vector<bool> pdiag_visit(2*n-1, false);
        vector<bool> scdiag_visit(2*n-1, false);
        
        n_queen(n, 0, res, currSet, col_visit, pdiag_visit, scdiag_visit);
        
        return res;
    }
};