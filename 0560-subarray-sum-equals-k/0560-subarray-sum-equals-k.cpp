class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map <int, int> sum_map;   //Using maps instead of 2-pointers since we can have -ve numbers
        
        int i, n = nums.size(), cum_sum = 0, res = 0;
        
        sum_map[0] = 1;     //Initializing sum=0 to 1 because we can also have 1 empty array
        
        for(i=0; i<n; i++){
            cum_sum += nums[i];
            
            if(sum_map.find(cum_sum - k) != sum_map.end())
                res += sum_map[cum_sum - k];
            
            sum_map[cum_sum]++;
            
        }
        return res;
    }
};