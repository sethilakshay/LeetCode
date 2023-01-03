class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size(), res = 0;
        int left = 0, right = 0;
        
        while(right < n-1){
            
            int max_jump = 0;
            for(int i=left; i<=right; i++){
                max_jump = max(max_jump, nums[i] + i - right);
            }
            
            left = right+1;
            right += max_jump;
            res++;
        }
        return res;
    }
};