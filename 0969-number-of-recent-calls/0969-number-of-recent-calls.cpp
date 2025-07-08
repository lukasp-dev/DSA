class RecentCounter {
public:
    vector<int> times;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        times.push_back(t);
        int look = max(0, t-3000);

        auto it = lower_bound(times.begin() , times.end(), look);
        return times.end() - it;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */