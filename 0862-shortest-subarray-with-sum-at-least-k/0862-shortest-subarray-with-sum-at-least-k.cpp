class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {
        int ans = INT_MAX, n = arr.size();
        deque<int> dq;
        vector<long long> v(n); // Prefix array
        v[0] = arr[0];
        
        for(int i=0; i<n; ++i) {
            if(i > 0) {
                v[i] = arr[i] + v[i-1]; // Prefix Sum
            }
            
            if(v[i] >= k) {
                ans = min(ans, i+1); // The subarray 0'th to i'th index can be an answer
            }
            
            while(size(dq) && v[i] - v[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            
            while(size(dq) && v[dq.back()] >= v[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};