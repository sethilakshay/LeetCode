class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX;
        
        deque<int> dq_idx;
        vector<long long> pref_sum(n, 0);
        pref_sum[0] = nums[0];
        
        for(int i=0; i<n; i++){
            
            if(i > 0){
                pref_sum[i] = pref_sum[i-1] + nums[i];
            }
            
            if(pref_sum[i] >= k){
                res = min(res, i+1);
            }
            
            while(!dq_idx.empty() && pref_sum[i] - pref_sum[dq_idx.front()] >= k){
                res = min(res, i - dq_idx.front());
                dq_idx.pop_front();
            }
            
            while(!dq_idx.empty() && pref_sum[dq_idx.back()] > pref_sum[i]){
                dq_idx.pop_back();
            }
            
            dq_idx.push_back(i);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};