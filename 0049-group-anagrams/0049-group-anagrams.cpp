class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, int> hash_map;
        vector<vector<string>> res;
        
        for(int i=0; i<strs.size(); i++){
            
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            
            if(hash_map.find(temp) == hash_map.end()){
                res.push_back(vector<string> ());
                hash_map[temp] = res.size()-1;
            }
            
            res[hash_map[temp]].push_back(strs[i]);
            
        }
        return res;
    }
};