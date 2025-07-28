class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        else{
            const vector<pair<int, string>>& options = mp[key];
            int l = 0, r = options.size()-1;
            string res = "";
            while(l <= r){
                int mid = l + (r-l)/2;
                int timestamp_prev = options[mid].first;
                if(timestamp_prev == timestamp){
                    return options[mid].second;
                }else if(timestamp_prev > timestamp){
                    r = mid - 1;
                }else if(timestamp_prev < timestamp){
                    res = options[mid].second;
                    l = mid + 1;
                }
            }
            return res;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */