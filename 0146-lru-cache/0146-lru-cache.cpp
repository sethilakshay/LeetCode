class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>:: iterator> cache_map;
    list<pair<int, int>> cache;
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
    }
    
    
    int get(int key) {
        if(cache_map.find(key) == cache_map.end())
            return -1;
        
        int temp = cache_map[key]->second;
        cache.erase(cache_map[key]);
        cache.push_front({key, temp});
        cache_map[key] = cache.begin();
        
        return temp;
    }
    
    void put(int key, int value) {
        if(cache_map.find(key) != cache_map.end()){
            cache.erase(cache_map[key]);
            cache.push_front({key, value});
            cache_map[key] = cache.begin();
        }
        
        else if(cache.size() < capacity){
            cache.push_front({key, value});
            cache_map[key] = cache.begin();
        }
        
        else{
            int evict = cache.back().first;
            cache.pop_back();
            cache_map.erase(evict);
            
            cache.push_front({key, value});
            cache_map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */