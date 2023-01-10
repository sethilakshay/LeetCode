class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int idx1 = 0, idx2 = -1, res = 0, cnt = 0;
        
        for(int i=0; i<fruits.size(); i++){
            cnt++;
            if(fruits[idx1] == fruits[i]){
                idx1 = i;
            }
            else if(idx2 == -1 || fruits[idx2] == fruits[i]){
                idx2 = i;
            }
            else{
                cnt = abs(idx2 - idx1) + 1;
                
                idx2 = i;
                idx1 = i-1;
            }
            res = max(res, cnt);
        }
        return res;
    }
};