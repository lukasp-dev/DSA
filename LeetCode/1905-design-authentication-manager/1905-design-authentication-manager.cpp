class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> authTokens;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        authTokens[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if(authTokens.find(tokenId)== authTokens.end()) return;
        if(authTokens[tokenId] <= currentTime) return;
        authTokens[tokenId] = currentTime + timeToLive;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto it : authTokens){
            if(it.second > currentTime){
                count++;
            }
        }

        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */