class Compare{
public:
    bool operator ()(pair<char, int> a, pair<char, int> b){
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> hashMap;
        
        for(char c: s){
            hashMap[c]++;
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> maxHeap;
        
        for(auto it = hashMap.begin(); it != hashMap.end(); it++){
            maxHeap.push({it->first, it->second});
        }
        
        string res = "";
        pair<char, int> curr;
        pair<char, int> prev;
        
        while(!maxHeap.empty()){
            curr = maxHeap.top();
            maxHeap.pop();
            
            res += curr.first;
            curr.second--;
            
            if(prev.second != 0){
                maxHeap.push(prev);
            }
            
            prev = curr;
        }
        
        return res.size() == s.size() ? res : "";
    }
};