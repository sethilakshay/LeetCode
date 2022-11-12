class Solution {
public:

    bool find(vector<vector<char>>& board, string& word, int indx, vector<vector<bool>>& visited, int i, int j){ 
        if(indx == word.size()){
            return true;
        }
        int row = board.size(), col = board[0].size();
        
        if (i<0 || j<0 || i>=row || j>=col || word[indx]!=board[i][j] || visited[i][j]==true){
            return false;
        }
        
        bool res=false;
        
        visited[i][j]=true;
        
        res = res || find(board, word, indx+1, visited, i+1, j);
        if(!res)
            res = res || find(board, word, indx+1, visited, i-1, j);
        if(!res)
            res = res || find(board, word, indx+1, visited, i, j+1);
        if(!res)
            res = res || find(board, word, indx+1, visited, i, j-1);
        
        visited[i][j]=false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string& word){
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                bool res = find(board, word, 0, visited, i, j);
                if (res){
                    return true;
                }
            }
        }
        return false;
    }
};