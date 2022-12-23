class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int res = 0, cnt;
        
        for(int i=0; i<32; i++){
            cnt = 0;
            int mask = 1<<i;
            
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