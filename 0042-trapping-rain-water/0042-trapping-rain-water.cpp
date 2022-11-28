class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        vector<int> left(n);
        vector<int> right(n);
        
        int maxh = INT_MIN;
        for(int i=0; i<n; i++){
            
            if(height[i] > maxh){
                maxh = height[i];
            }
            left[i] = maxh;
        }
        
        maxh = INT_MIN;
        for(int i=n-1; i>=0; i--){
            
            if(height[i] > maxh){
                maxh = height[i];
            }
            right[i] = maxh;
        }
        
        for(int i=0; i<n; i++){
            res += min(left[i], right[i]) - height[i];
        }
        
        return res;
    }
};