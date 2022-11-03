class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        struct compare{
            bool operator()(pair<int, int>& a, pair<int, int> b){
                return a.second < b.second;
            }
        };
        
        unordered_map<int, int> hash_map;
        for(int num: nums){
            hash_map[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxq;
        
        for(auto it = hash_map.begin(); it != hash_map.end(); it++){

            maxq.push(make_pair(it->first, it->second));
        }
        
        vector<int> res;
        
        while(k > 0){
            res.push_back(maxq.top().first);
            maxq.pop();
            k--;
        }
        
        return res;
    }
};