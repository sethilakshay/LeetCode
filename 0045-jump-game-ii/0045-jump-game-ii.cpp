class Solution {
public:
    int jump(vector<int>& nums) {
        
        int res = INT_MAX, n = nums.size();
        
        if(n==1)
            return 0;
            
        vector<int> dp(n, INT_MAX-1);
        for(int i = n-2; i>= 0; i--){
            
            if(i + nums[i] >= n-1)
                dp[i] = 1;
            
            else{
                for(int j = i+1; j < n-1; j++){
                    
                    if(i + nums[i] >= j)
                        dp[i] = min(dp[i], 1+dp[j]);
                }
            }
        }
        return dp[0];
    }
};