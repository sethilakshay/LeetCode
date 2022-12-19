class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        long long i = 0, j = 0, res = 0, window_sum = 0, window_len;

        while(j < nums.size() && i <= j){
            
            window_sum += nums[j];
            
            while((j-i+1)*nums[j]-window_sum > k){
                window_sum -= nums[i];
                i++;
            }

            res = max(res, j-i+1);
            j++;

        }
        
        return res;
    }
};