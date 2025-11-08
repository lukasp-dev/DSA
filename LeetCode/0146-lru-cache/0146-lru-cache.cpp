class LRUCache {
private:
    int capacity;
    list<int> order;
    unordered_map<int, pair<list<int>::iterator, int>> lookup;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = lookup.find(key);
        if(it == lookup.end()) return -1;

        auto orderIt = lookup[key].first;
        order.erase(orderIt);

        order.push_front(key);
        lookup[key].first = order.begin();

        return lookup[key].second;
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);
        if(it != lookup.end()){
            auto orderIt = it->second.first;
            order.erase(orderIt);
        }

        order.push_front(key);
        lookup[key] = make_pair(order.begin(), value);

        if(order.size() > capacity){
            auto it = order.end(); it--;
            lookup.erase(*it);
            order.erase(it);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */