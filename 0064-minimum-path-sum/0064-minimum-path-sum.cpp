class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        // Creating a Padding for DP
        vector<vector<int>> dp(row+1, vector<int> (col+1, INT_MAX));
        
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
                
                if(min(dp[i+1][j], dp[i][j+1]) == INT_MAX){
                    dp[i][j] = grid[i][j];
                }
                else{
                    dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};