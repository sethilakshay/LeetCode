class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        vector<vector<int>> freq(votes[0].size(), vector<int>(26, 0));
        
        for(int i=0; i<votes[0].size(); i++){
            for(string vote: votes){
                freq[i][vote[i] - 'A']++;
            }
        }
        
        string res = votes[0];
        
        sort(res.begin(), res.end(), [freq](char& a, char& b){
            
            for(int i=0; i<freq.size(); i++){
                if(freq[i][a - 'A'] == freq[i][b - 'A']){
                    continue;;
                }
                return freq[i][a - 'A'] > freq[i][b - 'A'];
            }
            return a < b;
        });
        return res;
    }
};