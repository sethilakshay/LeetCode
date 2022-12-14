class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        // When string is empty, 1 way to decode it
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        
        for(int i=1; i<n; i++){
            if(s[i] != '0'){
                dp[i+1] = dp[i];
            }
            
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                dp[i+1] += dp[i-1];
            }
        }
        
        return dp[n];
    }
};