class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int xor_num = 0;
        
        for(int i=0; i<nums.size(); i++){
            xor_num ^= nums[i];
        }
        
        int mask = 0;
        
        for(int i=0; i<32; i++){
            
            mask = 1<<i;
            if((xor_num&mask) != 0){
                break;
            }
        }
        
        int xor_num1 = 0, xor_num2 = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            if((nums[i]&mask) != 0){
                xor_num1 ^= nums[i];
            }
            else{
                xor_num2 ^= nums[i];
            }
        }
        return {xor_num1, xor_num2};
    }
};