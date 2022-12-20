class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int idx1 = 0, idx2 = -1, res = 0, count = 0;
        
        for(int i=0; i<fruits.size(); i++){
            count++;
            if(fruits[i] == fruits[idx1]){
                idx1 = i;
            } else if(idx2 == -1 || fruits[i] == fruits[idx2]){
                idx2 = i;
            } else {
                
                count = abs(idx1 - idx2) + 1;
                idx1 = i-1;
                idx2 = i;
            }
            res = max(res, count);
        }
        //res = max(res, count);
        return res;
    }
};