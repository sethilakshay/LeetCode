class compare{
  public:
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        
        for(int num: nums){
            hash_map[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> max_heap;
        vector<int> res;
        
        for(auto it=hash_map.begin(); it!=hash_map.end(); it++){
            max_heap.push({it->second, it->first});
        }
        
        while(k>0){
            res.push_back(max_heap.top().second);
            max_heap.pop();
            k--;
        }
        return res;
    }
};