class Solution {
public:
    //TC: O(N)
    int trap(vector<int>& height) {
        int n = height.size(), res = 0, max_h = INT_MIN;
        
        vector<int> left_h(n, 0);   //Storing the maximum encountered height on the left side
        vector<int> right_h(n, 0);  //Storing the maximum encountered height on the right side
        
        for(int i=0; i<n; i++){
            max_h = max(max_h, height[i]);
            left_h[i] = max_h;
        }
        
        max_h = INT_MIN;    //Very important here to re-initialize
        for(int i=n-1; i>=0; i--){
            max_h = max(max_h, height[i]);
            right_h[i] = max_h;
        }
        
        for(int i=0; i<n; i++){
            res += min(left_h[i], right_h[i]) - height[i];
        }
        
        return res;
    }
};