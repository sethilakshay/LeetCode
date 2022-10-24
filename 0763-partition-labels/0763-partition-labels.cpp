class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.size(), max_id = 0, len = 0;
        //Intialziing vector to -1 to only include ID's of letters encountered
        vector<int> lastId (26, -1);
        
        vector<int> res;
        
        for (int i=0; i<n; i++)
            lastId[s[i]-'a'] = i;
        
        for(int i=0; i<n; i++){
            max_id = max(max_id, lastId[s[i]-'a']);
            len++;
            
            if(i == max_id){
                res.push_back(len);
                len = 0;
            }
        }
        
        return res;
    }
};