class compare{
public:
    bool operator()(pair<char, int>& a, pair<char, int>& b){
        return a.second<b.second;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> hash_map;
        for(char c: s){
            hash_map[c]++;
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> max_heap;
        
        for(auto it=hash_map.begin(); it!= hash_map.end(); it++){
            max_heap.push({it->first, it->second});
        }
        
        pair<char, int> curr;
        pair<char, int> prev;
        string res = "";
        
        while(!max_heap.empty()){
            
            curr = max_heap.top();
            max_heap.pop();
            
            res += curr.first;
            curr.second--;
            
            if(prev.second > 0){
                max_heap.push(prev);
            }
            prev = curr;
        }
        return s.size() == res.size() ? res : "";
    }
};