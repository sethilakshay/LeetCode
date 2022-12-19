class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        long long i = 0, j = 0, res = 0, window_sum = 0, window_len;

        while(j < nums.size() && i <= j){
            
            window_sum += nums[j];
            window_len = j-i+1;
            
            if(window_len*nums[j]-window_sum <= k){
                res = max(res, window_len);
                j++;
            }
            else{
                window_sum -= nums[i] + nums[j];
                i++;
            }
        }
        
        return res;
    }
};