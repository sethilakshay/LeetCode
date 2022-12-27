class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(), col = matrix[0].size();
        
        int lo = 0, hi = (row*col) - 1, mid, r, c;
        
        while(lo<=hi){
            
            mid = lo + (hi-lo)/2;
            r = mid/col;
            c = mid%col;
            
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] < target){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return false;
    }
};