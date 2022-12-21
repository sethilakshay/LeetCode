class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> hash_map;
        priority_queue<pair<int, char>> max_heap;
        
        for(char c: s){
            hash_map[c]++;
        }
        
        for(auto it = hash_map.begin(); it != hash_map.end(); it++){
            max_heap.push(make_pair(it->second, it->first));
        }
        
        pair<int, char> curr;
        pair<int, char> prev;
        string res = "";
        
        while(!max_heap.empty()){
            
            curr = max_heap.top();
            max_heap.pop();
            
            res += curr.second;
            curr.first--;
            
            if(prev.first != 0){
                max_heap.push(prev);
            }
            
            prev = curr;
        }
        
        return res.size() == s.size() ? res : "";
    }
};