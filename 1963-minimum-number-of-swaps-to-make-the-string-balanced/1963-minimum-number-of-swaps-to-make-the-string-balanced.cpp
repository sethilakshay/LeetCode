class Solution {
public:
    int minSwaps(string s) {
        
        int res = 0, max_c = 0, cnt = 0;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == '['){
                cnt--;
            }
            else{
                cnt++;
            }
            
            max_c = max(max_c, cnt);
        }
        
        return ceil((double)max_c/2);
        
    }
};