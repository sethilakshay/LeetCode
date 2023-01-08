class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0, column=matrix[0].size()-1,mid;
        //Getting the Largest element in the row and smallest in column
        while(row<=(matrix.size()-1) && column>=0){
            //checking if this is equal to target
            if(matrix[row][column]==target){
                return true;
            }
            //if the element(largest in its row and smallest in the column)<target 
            //then entire row can be discarded!!!
            else if(matrix[row][column]<target){
                row+=1;
            }
            //if the element(largest in its row and smallest in the column)>target 
            //then entire column can be discarded!!!
            else{
                column-=1;
            }
        }
     return false;   
    }
};