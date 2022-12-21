class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size(), res = INT_MAX;
        deque<int> dq;
        
        vector<long long> pref_sum(n);
        pref_sum[0] = nums[0];
        
        for(int i=0; i<n; i++){
            
            if(i>0){
                pref_sum[i] = nums[i] + pref_sum[i-1];
            }
            
            if(pref_sum[i] >= k){
                res = min(res, i+1);
            }
            
            while(!dq.empty() && pref_sum[i] - pref_sum[dq.front()] >= k){
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            
            while(!dq.empty() && pref_sum[dq.back()] >= pref_sum[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};