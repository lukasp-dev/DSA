class AuthenticationManager {
public:
    int ttl;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq; // lazy
    unordered_map<string, int> times;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        times[tokenId] = currentTime + ttl;
        pq.push({times[tokenId], tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        cleanUp(currentTime);
        if (!times.count(tokenId))
            return;
        times[tokenId] = currentTime + ttl; // lazy popping at unexpiry.
        pq.push({times[tokenId], tokenId});

    }
    
    int countUnexpiredTokens(int currentTime) {
        cleanUp(currentTime);
        return times.size();
    }

    void cleanUp(int currentTime) {
        while (!pq.empty() && pq.top().first <= currentTime) {
            auto cur = pq.top();
            pq.pop();
            if (cur.first == times[cur.second])
                times.erase(cur.second);
        }
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */