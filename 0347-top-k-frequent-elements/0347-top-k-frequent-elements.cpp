class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        
        for(int num: nums){
            hash_map[num]++;
        }
        
        priority_queue<pair<int, int>> maxq;
        
        for(auto it: hash_map){
            maxq.push(make_pair(it.second, it.first));
        }
        
        vector<int> res;
        while(k > 0){
            res.push_back(maxq.top().second);
            maxq.pop();
            k--;
        }
        
        return res;
    }
};