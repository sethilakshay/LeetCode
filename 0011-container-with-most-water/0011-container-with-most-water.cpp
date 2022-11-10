class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size(), maxA = 0;
        int i = 0, j = n-1;
        
        while(i<j){
            
            if(height[j] <= height[i]){
                
                maxA = max(maxA, (j-i)*height[j]);
                j--;
            }
            
            else{
                maxA = max(maxA, (j-i)*height[i]);
                i++;
            }
        }
        return maxA;
    }
};