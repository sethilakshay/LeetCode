class compare{
public:
    bool operator() (pair<char, int>& a, pair<char, int>& b){
        return a.second<b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> map;
        for(char c: s){
            map[c]++;
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> max_heap;
        
        for(auto it = map.begin(); it != map.end(); it++){
            max_heap.push({it->first, it->second});
        }
        
        string new_word = "";
        pair<char, int> curr;
        pair<char, int> prev;
        
        while(!max_heap.empty()){
            curr = max_heap.top();
            max_heap.pop();
            
            new_word += curr.first;
            curr.second--;
            
            if(prev.second != 0)
                max_heap.push(prev);
            
            prev = curr;
        }
        
        return new_word.size() == s.size() ? new_word : "";
    }
};