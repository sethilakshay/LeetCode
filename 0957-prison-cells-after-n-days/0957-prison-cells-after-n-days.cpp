class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map <string, int> hash_map;
        
        for(int i=0; i<n; i++){
            string s (cells.begin(), cells.end());
            //When true, means the loop started repeating
            if (hash_map.find(s) != hash_map.end()){
                int cycle_l = i - hash_map[s];
                int rem_days = (n-i)%cycle_l;
                return prisonAfterNDays(cells, rem_days);
            }
            
            else{
                hash_map[s] = i;
                
                vector<int> temp(cells.size(), 0);
                for(int j=1; j<cells.size()-1; j++){    //Simulating the remaining positions
                    temp[j] = s[j-1] == s[j+1] ? 1 : 0;
                }
                cells = temp;
            }
        }
        
        //In case if n is small so that no looping is being able to form
        return cells;
    }
};