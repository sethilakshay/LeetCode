class Solution {
public:
    // Harder version of Leetcode 209
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size(), res = INT_MAX;
        vector<long long> pref_sum(n, 0);
        pref_sum[0] = nums[0];
        
        // To store indexes of monotonically increasing sum
        deque<int> monoDq;
        
        for(int i=0; i<n; i++){
            
            if(i > 0){
                pref_sum[i] = pref_sum[i-1] + nums[i];
            }
            
            if(pref_sum[i] >= k){
                res = min(res, i+1);
            }
            
            while(!monoDq.empty() && pref_sum[i] - pref_sum[monoDq.front()] >= k){
                res = min(res, i - monoDq.front());
                monoDq.pop_front();
            }
            
            while(!monoDq.empty() && pref_sum[monoDq.back()] > pref_sum[i]){
                monoDq.pop_back();
            }
            
            monoDq.push_back(i);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};