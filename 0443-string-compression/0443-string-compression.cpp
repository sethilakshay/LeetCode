class Solution {
public:
    int compress(vector<char>& chars) {
        
        
        int start = 0, i, cnt = 1;
        char curr_char = chars[start];
        
        for(i = 1; i < chars.size(); i++){
            
            if(chars[i] == curr_char){
                cnt++;
            }
            
            else{
                chars[start] = chars[i-1];
                start++;
                
                if(cnt > 1){
                    string cnt_str = to_string(cnt);
                    
                    for(char c: cnt_str){
                        chars[start] = c;
                        start++;
                    }
                }
                
                curr_char = chars[i];
                cnt = 1;
            }
        }
        
        chars[start] = chars[i-1];
        start++;
        
        if(cnt > 1){
            string cnt_str = to_string(cnt);

            for(char c: cnt_str){
                chars[start] = c;
                start++;
            }
        }
        
        return start;
    }
};