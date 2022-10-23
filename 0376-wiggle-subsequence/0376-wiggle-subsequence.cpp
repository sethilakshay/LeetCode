class Solution {
public:
    //TC: O(N^2) 
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size(), res = 1;   //Res initialized to 1 since atleast 1 element will be there
        
        //Creating a n*2 vector where n[0] is when wiggle starts with +ve and n[1] is for -ve
        //All initialized to 1 since the smallest subsequence will contain atleast 1 element
        vector<vector<int>> dp(n, vector<int>(2, 1));
        
        for(int i=1; i<n; i++){
            
            for(int j=i-1; j>=0; j--){
                
                //Postive start
                if(nums[i] - nums[j] > 0)
                    dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
        
                //Negative start
                else if(nums[i] - nums[j] < 0)
                    dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
    
            }
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};