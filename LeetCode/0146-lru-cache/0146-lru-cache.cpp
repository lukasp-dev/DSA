class LRUCache {
public:
    int capacity;
    list<int> order;
    unordered_map<int, pair<list<int>::iterator, int>> lookup;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = lookup.find(key);
        if(it == lookup.end()) return -1;
        int res = it->second.second;
        auto orderIt = it->second.first;
        order.erase(orderIt);
        order.push_front(key);
        it->second.first = order.begin();
        return res;
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);
        if(it != lookup.end()){
            it->second.second = value;
            auto orderIt = it->second.first;
            order.erase(orderIt);
        }

        order.push_front(key);
        lookup[key] = {order.begin(), value};

        if(order.size() > capacity){
            auto endIt = order.end(); endIt--;
            int key = *endIt;
            order.erase(endIt);
            lookup.erase(key);
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */