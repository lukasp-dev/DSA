class HitCounter {
public:
    struct Bucket {
        int timestamp;
        int count;
    };

    vector<Bucket> hit_map;

    HitCounter() : hit_map(300, Bucket{-1, 0}) {}
    
    void hit(int timestamp) {
        // Several hits may happen at the same timestamp.
        int idx = timestamp % 300;
        
        if(hit_map[idx].timestamp != timestamp) {
            hit_map[idx].count = 0;
        }

        hit_map[idx].timestamp = timestamp;
        hit_map[idx].count++;
    }
    
    int getHits(int timestamp) {
        int count = 0;

        for(Bucket b : hit_map) {
            if(b.timestamp > timestamp - 300) {
                count += b.count;
            }
        }

        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */