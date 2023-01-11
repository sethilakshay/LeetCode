class Solution {
public:
    int jump(vector<int>& nums) {
        
        int left = 0, right = 0, res = 0;
        
        while(right < nums.size()-1){
            
            int max_jump = 0;
            for(int i=left; i<=right; i++){
                max_jump = max(max_jump, i+nums[i]-right);
            }
            
            left = right+1;
            right += max_jump;
            res++;
        }
        return res;
    }
};