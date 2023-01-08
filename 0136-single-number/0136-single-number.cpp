class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int xor_num = 0;
        
        for(int num: nums){
            xor_num ^= num;
        }
        return xor_num;
    }
};