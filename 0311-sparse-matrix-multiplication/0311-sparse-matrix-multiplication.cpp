class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        
        int mat_1r = mat1.size(), mat_1c_2r = mat2.size(), mat_2c = mat2[0].size();
        
        vector<vector<int>> res(mat_1r, vector<int>(mat_2c, 0));
        
        for(int i=0; i<mat_1r; i++){
            
            for(int j=0; j<mat_2c; j++){
                
                for(int k=0; k<mat_1c_2r; k++){
                    
                    res[i][j] += mat1[i][k]*mat2[k][j];
                }   
            }
        }
        
        return res;
    }
};