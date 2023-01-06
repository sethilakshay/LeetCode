class Solution {
public:
    string sortSentence(string s) {
        
        map<int, string> str_map;
        s.push_back(' ');
        
        for(int i=0; i<s.size(); i++){
            
            int j = i;
            string curr_word = "";
            while(s[j] != ' '){
                curr_word += s[j];
                j++;
            }
            i = j;
            int word_pos = (curr_word[curr_word.size()-1] - '0');
            curr_word.pop_back();
            
            str_map[word_pos] = curr_word;
        }
        string ans = "";
        
        for(auto it = str_map.begin(); it != str_map.end(); it++){
            ans += it->second;
            ans += ' ';
        }
        
        ans.pop_back();
        return ans;
    }
};