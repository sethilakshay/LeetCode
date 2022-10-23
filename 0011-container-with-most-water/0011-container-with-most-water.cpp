class Solution {
public:
    //2 Pointer Solution
    int maxArea(vector<int>& height) {
        
        int max_area = 0, n = height.size();
        int i = 0, j = n-1;
        
        while(i<j){
            
            if(height[j]<=height[i]){
                max_area = max((j-i)*height[j], max_area);
                j--;
            }
            
            else{
                max_area = max((j-i)*height[i], max_area);
                i++;
            }
        }
        return max_area;
    }
};