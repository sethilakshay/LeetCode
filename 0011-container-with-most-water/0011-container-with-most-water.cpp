class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), res = 0;
        int i = 0, j = n-1;
        
        while(i<j){
            if(height[i] < height[j]){
                res = max((j-i)*height[i], res);
                i++;
            }
            else{
                res = max((j-i)*height[j], res);
                j--;
            }
        }
        return res;
    }
};