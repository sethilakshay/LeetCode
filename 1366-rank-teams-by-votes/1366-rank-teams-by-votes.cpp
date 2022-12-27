class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        string out = votes[0];
        
        for(int i=0; i<n; i++){
            for(string vote: votes){
                freq[i][vote[i] - 'A']++;
            }
        }
        
        sort(out.begin(), out.end(), [freq](char& a, char& b){
            for(int i=0; i<freq.size(); i++){
                if(freq[i][a - 'A'] == freq[i][b - 'A']){
                    continue;
                }
                else{
                    return freq[i][a - 'A'] > freq[i][b - 'A'];
                }
            }
            return a<b;
        });
        
        return out;
    }
};