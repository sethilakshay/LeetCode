class Solution {
public:
    int compress(vector<char>& chars) {
        
        int start = 0, cnt = 1, n = chars.size();
        char start_char = chars[start];
        
        for(int i=1; i<=n; i++){
            
            if(i<n && start_char == chars[i]){
                cnt++;
            }
            else{
                chars[start] = start_char;
                start++;
                
                if(cnt > 1){
                    string str_cnt = to_string(cnt);
                    
                    for(char c: str_cnt){
                        chars[start] = c;
                        start++;
                    }
                }
                
                if(i < n){
                    start_char = chars[i];
                    cnt = 1;
                }
            }
        }
        return start;
    }
};