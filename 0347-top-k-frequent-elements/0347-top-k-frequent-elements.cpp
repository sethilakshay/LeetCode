class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        
        for(int num: nums){
            hash_map[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> res;
        
        for(auto it=hash_map.begin(); it!=hash_map.end(); it++){
            min_heap.push({it->second, it->first});
            
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        
        while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};