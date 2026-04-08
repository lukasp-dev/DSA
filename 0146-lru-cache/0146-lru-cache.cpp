class LRUCache {
int capacity;

list<pair<int, int>> cache;
unordered_map<int, list<pair<int, int>>::iterator> lookup;

public:
    LRUCache(int capacity): capacity{capacity}{}
    
    int get(int key) {
        if(lookup.count(key)){
            cache.splice(cache.end(), cache, lookup[key]);
            return lookup[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lookup.count(key)){
            cache.splice(cache.end(), cache, lookup[key]);
            lookup[key]->second = value;
        }else{
            if(cache.size() == capacity){
                int key_to_evict = cache.front().first;
                lookup.erase(key_to_evict);
                cache.pop_front();
            }
            cache.push_back(make_pair(key, value));
            lookup[key] = prev(cache.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 /**
 * void splice(const_iterator pos, list& other, const_iterator it);
 */