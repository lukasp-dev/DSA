class LRUCache {
private:
    int capacity;
    list<int> recentKeys;
    unordered_map<int, pair<int, list<int>::iterator>> lookup;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!lookup.count(key)){
            return -1;
        }else{
            int res = lookup[key].first;
            auto oldIt = lookup[key].second;

            recentKeys.erase(oldIt);
            recentKeys.push_front(key);
            lookup[key].second = recentKeys.begin();

            return res;
        }
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);
        if(it != lookup.end()){
            auto keyIt = lookup[key].second;
            recentKeys.erase(keyIt);
        }
        recentKeys.push_front(key);
        lookup[key] = {value, recentKeys.begin()};

        if(recentKeys.size() > capacity){
            auto endIt = recentKeys.end(); endIt--;
            lookup.erase(*endIt);
            recentKeys.erase(endIt);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */