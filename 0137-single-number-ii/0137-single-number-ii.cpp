class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int count = 0, mask = 0, res = 0;
        
        for(int i=0; i<32; i++){
            mask = 1<<i;
            count = 0;
            
            for(int num: nums){
                
                if((num&mask) != 0){
                    count++;
                } 
            }
            
            if(count%3 != 0){
                res = (res|mask);
            }
        }
        return res;
    }
};