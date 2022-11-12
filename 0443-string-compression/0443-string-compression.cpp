class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i , n = chars.size(), cnt = 1, start = 0;
        char curr_char = chars[start];
        
        for(i=1; i<=n; i++){
            
            if(i<n && curr_char == chars[i]){
                cnt++;
            }
            
            else{
                chars[start] = chars[i-1];
                start++;
                
                if(cnt > 1){
                    
                    string str_cnt = to_string(cnt);
                    
                    for(char c: str_cnt){
                        chars[start] = c;
                        start++;
                    }
                }
                
                if(i<n){
                    cnt = 1;
                    curr_char = chars[i];
                }
            }
            
        }
        return start;
    }
};