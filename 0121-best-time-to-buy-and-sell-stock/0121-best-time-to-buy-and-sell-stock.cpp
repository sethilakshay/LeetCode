class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int res = 0, buy = INT_MAX;
        
        for(int i=0; i<prices.size(); i++){
            
            buy = min(buy, prices[i]); 
            res = max(res, prices[i] - buy);
        }
        return res;
    }
};