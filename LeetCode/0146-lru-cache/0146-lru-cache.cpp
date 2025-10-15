class LRUCache {
public:
    int capacity;
    list<int> order;
    map<int, pair<list<int>::iterator, int>> lookup;

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = lookup.find(key);
        if (it == lookup.end()) return -1;
        int value = it->second.second;
        order.erase(it->second.first);
        order.push_front(key);
        it->second.first = order.begin();
        return value;
    }

    void put(int key, int value) {
        auto it = lookup.find(key);
        if (it != lookup.end()) order.erase(it->second.first);
        order.push_front(key);
        lookup[key] = {order.begin(), value};
        if ((int)order.size() > capacity) {
            int oldKey = order.back();
            order.pop_back();
            lookup.erase(oldKey);
        }
    }
};
