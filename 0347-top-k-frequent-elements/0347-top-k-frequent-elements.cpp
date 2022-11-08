class compare{
public:
    
    bool operator() (pair<int, int> a, pair<int, int>b){
        return b.first < a.first;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> min_heap;
        
        for (int i=0; i<nums.size(); i++){
            hash_map[nums[i]]++;
        }
        
        for(auto it=hash_map.begin(); it!=hash_map.end(); it++){
            
            int num  = it->first;
            int cnt = it->second;
            
            if(min_heap.size() < k)
                min_heap.push(make_pair(cnt, num));            
            
            else{
                if(cnt > min_heap.top().first){
                    min_heap.pop();
                    min_heap.push(make_pair(cnt, num));
                }    
            }
        }
        
        vector<int> res;
        while(!min_heap.empty()){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return res;
    }
};