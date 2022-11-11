class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, false);
        
        dp[n-1] = true;
        int goal = n-1;
        
        for(int i = n-2; i>= 0; i--){
            
            if(i + nums[i] >= goal){
                dp[i] = true;
                goal = i;
            }
            else{
                
                for(int j = 1; j <= nums[i]; j++){
                    if(dp[i+j]){
                        dp[i] = true;
                        goal = i;
                        break;
                    }
                    
                }
            }
        }
        return dp[0];
    }
};