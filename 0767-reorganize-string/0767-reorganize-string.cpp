class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> map;
        
        for(char c: s){
            map[c]++;
        }
        
        priority_queue<pair<int, char>> max_heap;
        
        for(auto it = map.begin(); it != map.end(); it++){
            max_heap.push({it->second, it->first});
        }
        
        string new_word = "";
        pair<int, char> curr;
        pair<int, char> prev;
        
        while(!max_heap.empty()){
            curr = max_heap.top();
            max_heap.pop();
            
            new_word += curr.second;
            curr.first--;
            
            if(prev.first != 0)
                max_heap.push(prev);
            
            prev = curr;
        }
        
        return new_word.size() == s.size() ? new_word : "";
    }
};