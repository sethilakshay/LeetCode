class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int mask = 0, cnt, res = 0;
        
        for(int i=0; i<32; i++){

            mask = 1<<i;
            cnt = 0;
            
            for(int j=0; j<nums.size(); j++){
                if((nums[j]&mask) != 0){
                    cnt++;
                }
            }
            
            if(cnt%3 != 0){
                res = (res|mask);
            }
        }
        return res;
    }
};