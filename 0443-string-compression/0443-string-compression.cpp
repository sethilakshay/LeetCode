class Solution {
public:
    int compress(vector<char>& chars) {
        
        char start_char = chars[0];
        int start = 0, cnt = 1;
        
        for(int i=1; i<=chars.size(); i++){
            
            if(i < chars.size() && start_char == chars[i]){
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
                
                if(i < chars.size()){
                    start_char = chars[i];
                    cnt = 1;
                }
            }
        }
        return start;
    }
};