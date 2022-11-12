class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //Key = Postive Remainder
        //Value = Number of times the positive remainder comes
        unordered_map<int, int> sum_map;
        
        int i, j, n = nums.size(), cum_sum = 0, rem, res = 0;
        sum_map[0] = 1; //Initializing rem=0 to 1 because of empty array
        
        for(i=0; i<n; i++){
            cum_sum += nums[i];     //Updating cumulative sum
            
            //Calculating remainder for cum_sum and checking if another sub-array with same remainder exists
            //However, if cum_sum is negative, then remainders will be negative
            //To get +ve remainders, simply add k to the -ve remainder
            
            rem = cum_sum%k;    //This remainder can be +ve or -ve depending on cum_sum            
            if(rem<0)           //Adjusting for negative remainders
                rem += k;
            
            if(sum_map.find(rem) != sum_map.end())
                res += sum_map[rem];
            
            sum_map[rem]++;
        }
        return res;
    }
};