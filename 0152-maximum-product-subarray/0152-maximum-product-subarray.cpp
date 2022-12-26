class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(), res;
        
        vector<int> maxProd(n);
        vector<int> minProd(n);
        
        maxProd[0] = nums[0];
        minProd[0] = nums[0];
        res = nums[0];
        
        for(int i=1; i<n; i++){
            
            maxProd[i] = max(nums[i], max(nums[i]*maxProd[i-1], nums[i]*minProd[i-1]));
            minProd[i] = min(nums[i], min(nums[i]*maxProd[i-1], nums[i]*minProd[i-1]));
            
            res = max(res, maxProd[i]);
                             
        }
        return res;
    }
};