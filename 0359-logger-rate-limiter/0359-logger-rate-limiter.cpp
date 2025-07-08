class Logger {
public:
    int curr_time;
    string str;
    unordered_map<string, int> mp;

    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message) != mp.end()){
            if(timestamp - mp[message] < 10) {
                return false;
            }
        }

        mp[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */