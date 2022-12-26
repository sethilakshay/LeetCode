class Solution {
public:
    // TC: O(n)
    // Greedy Solution in linear time
    int jump(vector<int>& nums) {
        
        int res = 0, n = nums.size();
        int left = 0, right = 0, farthest = 0;
        
        while(right < n-1){
            farthest = 0;
            
            for(int i=left; i<=right; i++){
                farthest = max(farthest, i-right+nums[i]);
            }
            
            left = right+1;
            right += farthest;
            res++;
        }
        return res;
    }
};