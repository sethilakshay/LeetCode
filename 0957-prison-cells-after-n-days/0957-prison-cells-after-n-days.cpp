class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map <string, int> hash_map;
        
        for(int i=0; i<n; i++){
            string s (cells.begin(), cells.end());
            
            if (hash_map.find(s) != hash_map.end()){    //When true, that means the loop has started repeating
                int cycle_l = i - hash_map[s];
                int rem_days = (n-i)%cycle_l;
                return prisonAfterNDays(cells, rem_days);
            }
            
            else{
                hash_map[s] = i;
                
                vector<int> temp;
                temp.push_back(0);  //The first Position will always be zero
                
                for(int j=1; j<cells.size()-1; j++){    //Simulating the remaining positions
                    int num = s[j-1] == s[j+1] ? 1 : 0;
                    temp.push_back(num);
                }
                temp.push_back(0);  //The last Position will always be zero
                
                cells = temp;
            }
        }
        
        //In case if n is small so that no looping is being able to form
        return cells;
    }
};