class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size(), i;
        
        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        
        for(i=1; i<n; i++){
            
            if(s[i] != '0')
                dp[i+1] = dp[i];
            
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                dp[i+1] += dp[i-1];
            }
            
        }
        return dp[n];
        
    }
};