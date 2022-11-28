class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        if(n<=1)
            return 0;
        
        vector<int> dp_buy(n, 0);
        vector<int> dp_sell(n, 0);
        
        dp_buy[0] = -prices[0];
        dp_sell[0] = 0;
        
        dp_buy[1] = max(dp_buy[0], -prices[1]);
        dp_sell[1] = max(dp_sell[0], dp_buy[0] + prices[1]);
        
        for(int i=2; i<n; i++){
            dp_buy[i] = max(dp_buy[i-1], dp_sell[i-2] - prices[i]);
            dp_sell[i] = max(dp_sell[i-1], dp_buy[i-1]+prices[i]);
        }
        return dp_sell[n-1];
    }
};