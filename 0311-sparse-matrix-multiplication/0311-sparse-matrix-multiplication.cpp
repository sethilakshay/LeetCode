class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        
        int m = mat1.size(), n = mat2[0].size();
        
        vector<vector<int>> res(m, vector<int> (n, 0));
        
        
        for(int i=0; i<m; i++){
            
            int curr_col = 0;
            
            while(curr_col < n){
                
                for(int j=0; j<mat2.size(); j++){
                    res[i][curr_col] += mat1[i][j]*mat2[j][curr_col];
                }
                curr_col++;
            }
            
        }
        return res;
    }
};