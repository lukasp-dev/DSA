class LRUCache {
public:
    unordered_map<int, int> cache;
    vector<int> list;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            auto it = find(list.begin(), list.end(), key);
            list.erase(it, it+1);
            list.push_back(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            auto it = find(list.begin(), list.end(), key);
            list.erase(it, it+1);
        }else{
            if(list.size() == capacity){
                int target = list[0];
                cache.erase(target);

                list.erase(list.begin(), list.begin() + 1);
            }
        }
        list.push_back(key);

        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */