class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> authTokens;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        cleanup(currentTime);
        authTokens[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        cleanup(currentTime);
        if(authTokens.find(tokenId)== authTokens.end()) return;
        if(authTokens[tokenId] <= currentTime) return;
        authTokens[tokenId] = currentTime + timeToLive;
    }

    void cleanup(int currentTime){
        auto it = authTokens.begin(); 
        for(it; it!=authTokens.end();){
            if(it->second <= currentTime){
                it = authTokens.erase(it);
            }else{
                it++;
            }
        }
    }

    int countUnexpiredTokens(int currentTime) {
        cleanup(currentTime);
        return authTokens.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */