class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(), col = matrix[0].size();
        
        int lo = 0, hi = row*col-1, mid;
        
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
    
            int r = mid/col;
            int c = mid%col;

            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] > target){
                hi = mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return false;
    }
};