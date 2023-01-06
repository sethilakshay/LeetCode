class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int old_row = box.size(), old_col = box[0].size();
        int row = old_col, col = old_row;
        vector<vector<char>> rotated_box(row, vector<char> (col, '.'));
        
        // Rotating the box
        for(int i=0; i<old_row; i++){
            for(int j=0; j<old_col; j++){
                rotated_box[j][old_row - i - 1] = box[i][j];
            }
        }
        
        // Pushing them down
        for(int i=0; i<col; i++){
            
            queue<int> idx;
            for(int j=row-1; j>=0; j--){
                
                if(rotated_box[j][i] == '.'){
                    idx.push(j);
                }
                else if(rotated_box[j][i] == '*'){
                    idx = queue<int>();
                }
                else{
                    if(idx.empty()){
                        continue;
                    }
                    else{
                        swap(rotated_box[j][i], rotated_box[idx.front()][i]);
                        idx.pop();
                        idx.push(j);
                    }
                }
            }
        }
        return rotated_box;        
    }
};