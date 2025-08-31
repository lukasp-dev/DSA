class Twitter {
public:
    int time;
    struct Tweet{
        int tweetId;
        int timeStamp;
    };
    unordered_map<int, vector<Tweet>> posts;
    unordered_map<int, unordered_set<int>> followings;

    Twitter() {
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({tweetId, time++});
    }
    
    struct cmp {
        bool operator()(const Tweet& a, const Tweet& b){
            return a.timeStamp > b.timeStamp;
        }
    };

    vector<int> getNewsFeed(int userId) {
        unordered_set<int> myFollowings = followings[userId];
        priority_queue<Tweet, vector<Tweet>, cmp> pq; 

        if (posts.count(userId)) {
            for (auto &t : posts[userId]) {
                pq.push(t);
                if (pq.size() > 10) pq.pop();
            }
        }

        for(int follower : myFollowings){
            vector<Tweet>& tweets= posts[follower];
            for(Tweet tweet : tweets){
                pq.push(tweet);
                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }

        vector<int> vec;

        while(!pq.empty()){
            Tweet curr = pq.top(); pq.pop();
            vec.push_back(curr.tweetId);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */