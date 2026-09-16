class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<vector<pair<int, int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() : buckets(SIZE) {}
    
    void put(int key, int value) {
        int hashed_key = hash(key);
        
        for(auto &[k, v] : buckets[hashed_key]) {
            if(k == key) {
                v = value;
                return;
            }
        }

        buckets[hashed_key].push_back({key, value});
    }
    
    int get(int key) {
        int hashed_key = hash(key);

        for(auto &[k, v] : buckets[hashed_key]) {
            if(k == key) {
                return v;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int hashed_key = hash(key);
        auto& bucket = buckets[hashed_key];
        
        for(int i=0; i<bucket.size(); ++i) {
            auto curr = bucket[i];
            if(curr.first == key) {
                bucket.erase(bucket.begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */