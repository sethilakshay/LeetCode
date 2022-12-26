class compare{
  public:
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return b.first<a.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        
        for(int num: nums){
            hash_map[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> min_heap;
        vector<int> res;
        
        for(auto it=hash_map.begin(); it!=hash_map.end(); it++){
            
            if(min_heap.size() < k){
                min_heap.push({it->second, it->first});
            }
            else{
                if(min_heap.top().first < it->second){
                    min_heap.pop();
                    min_heap.push({it->second, it->first});
                }
            }
        }
        
        while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};