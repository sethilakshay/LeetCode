class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), mask=0, res=0;
        
        for (int i=0; i<32; i++){
            mask = 1<<i;
            int count = 0;
            for (int j=0; j<n; j++){
                if ((nums[j]&mask)!=0){
                    count++;
                }
            }
            if (count%2!=0){
                res = res|mask;
            }
        }
        return res;     
    }
};