class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int xor_num = 0;
        for(int i=1; i<=nums.size(); i++){
            xor_num ^= i^nums[i-1];
            
        }
        return xor_num;
    }
};