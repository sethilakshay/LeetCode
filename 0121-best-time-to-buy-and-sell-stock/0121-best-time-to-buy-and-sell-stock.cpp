class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = INT_MAX, res = 0;
        
        for(int i=0; i<prices.size(); i++){
            
            if(buy > prices[i]){
                buy = prices[i];
            }
            
            res = max(res, prices[i] - buy);
        }
        return res;
    }
};