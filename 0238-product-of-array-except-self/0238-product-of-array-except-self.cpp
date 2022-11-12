class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> res(n);
        
        for(int i=1; i<n; i++){
            left[i] = nums[i-1] * left[i-1];
            right[n-1-i] = right[n-i]*nums[n-i];
        }

        
        for(int i=0; i<n; i++){
            res[i] = left[i]*right[i];
        }
        return res;
    }
};