class Solution {
public:
    int compress(vector<char>& chars) {

        char start_char = chars[0];
        int cnt = 1, start = 0;
        
        for(int i=1; i<=chars.size(); i++){
            
            if(i < chars.size() && chars[i] == start_char){
                cnt++;
            }
            else{
                chars[start] = start_char;
                start++;
                
                string cnt_num = to_string(cnt);
                
                if(cnt > 1){
                    for(char c: cnt_num){
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