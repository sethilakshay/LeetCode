class Solution {
public:
    int compress(vector<char>& chars) {
        
        int start = 0, i, n = chars.size(), cnt = 1;
        
        char curr_char = chars[start];
        
        for(i=1; i<=n; i++){
            
            if(i<n && chars[i] == curr_char){
                cnt++;
            }
            else{
                chars[start] = curr_char;
                start++;
                
                if(cnt>1){
                    string cnt_str = to_string(cnt);
                
                    for(char c: cnt_str){
                    chars[start] = c;
                    start++;
                    }
                }
                
                if(i<n){
                    curr_char = chars[i];
                    cnt = 1;
                }
            }
        }
        return start;
    }
};