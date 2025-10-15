class LRUCache {
public:
    int capacity;
    list<int> LRUC;
    unordered_map<int, pair<list<int>::iterator, int>> lookup;

    LRUCache(int capacity) {
        this -> capacity = capacity;
    }

    
    int get(int key) {
        auto it = lookup.find(key);
        int res = -1;

        if(it != lookup.end()){
            auto [iterator, value] = lookup[key];
            res = value;
            LRUC.erase(iterator);
            LRUC.push_front(key);
            lookup[key] = {LRUC.begin(), res};
        }
        return res;
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);

        if(it != lookup.end()){
            auto listIterator = lookup[key].first;
            LRUC.erase(listIterator);
        }
        
        LRUC.push_front(key);
        lookup[key] = {LRUC.begin(), value};

        if(LRUC.size() > capacity){
            auto it = LRUC.end(); it--;
            lookup.erase(*it);
            LRUC.erase(it);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */