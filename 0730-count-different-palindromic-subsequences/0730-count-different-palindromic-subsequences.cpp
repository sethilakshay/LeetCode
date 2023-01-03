class Solution {
public:
    int countPalindromicSubsequences(string s) {
        
        int n = s.size(), mod = 1e9+7;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        
        for(int i=n-1; i>=0; i--){
            dp[i][i] = 1;
            
            for(int j=i+1; j<n; j++){
                
                if(s[i] != s[j]){
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
                // if s[i] == s[j] then 3 cases
                else{
                    dp[i][j] = 2*dp[i+1][j-1];
                    int left = i+1, right = j-1;
                    
                    while(left <= j-1 && s[left] != s[i]){
                        left++;
                    }
                    
                    while(i+1 <= right && s[right] != s[j]){
                        right--;
                    }
                    
                    // Case 1: means no char = s[i] in Palindrome
                    if(left > right){
                        dp[i][j] += 2;
                    }
                    else if(left == right){
                        dp[i][j] += 1;
                    }
                    else{
                        dp[i][j] -= dp[left+1][right-1];
                    }
                }
                dp[i][j] %= mod;
                if(dp[i][j] < 0){
                    dp[i][j] += mod;
                }
            }
        }
        return dp[0][n-1];
    }
};