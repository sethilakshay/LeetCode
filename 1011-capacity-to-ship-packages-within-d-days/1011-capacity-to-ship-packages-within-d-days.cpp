class Solution {
public:
    int findDays(int wt, vector<int>& weights){
        
        int days = 1, cum_sum = 0;
        
        for(int i=0; i<weights.size(); i++){
            
            if(cum_sum + weights[i] <= wt){
                cum_sum += weights[i];
            }
            else{
                cum_sum = weights[i];
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int max_weight = INT_MIN, cum_sum = 0;
        
        for(int i=0; i<weights.size(); i++){
            max_weight = max(weights[i], max_weight);
            cum_sum += weights[i];
        }
        
        int lo = max_weight, hi = cum_sum, mid;
        
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            
            if(findDays(mid, weights) <= days){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return hi;
    }
};