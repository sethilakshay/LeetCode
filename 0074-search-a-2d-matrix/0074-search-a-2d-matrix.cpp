class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(), col  = matrix[0].size();
        int lo = 0, hi = row-1, ideal_row;
        
        while(lo<=hi){
            ideal_row = lo + (hi-lo)/2;
            
            if(matrix[ideal_row][0] <= target && target <= matrix[ideal_row][col-1]){
                break;
            }
            else if(matrix[ideal_row][0] > target){
                hi = ideal_row - 1;
            }
            else{
                lo = ideal_row + 1;
            }
        }
        
        lo = 0, hi = col-1;
        int mid;
        
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            
            if(matrix[ideal_row][mid] == target){
                return true;
            }
            else if(matrix[ideal_row][mid] < target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return false;
    }
};