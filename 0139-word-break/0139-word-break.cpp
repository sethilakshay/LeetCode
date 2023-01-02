class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=1; i<=n; i++){
            
            for(string word: wordDict){
                
                if(i >= word.size() && s.substr(i-word.size(), word.size()) == word){
                    dp[i] = dp[i-word.size()];
                }
                
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[n];
    }
};