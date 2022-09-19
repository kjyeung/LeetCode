class Twitter {
public:
    int timestemp;
    
    class Tweet{
    public:
        int t;
        int id;
        Tweet* next;
        Tweet(int _t, int _id): t(_t), id(_id), next(nullptr){}
    };
    
    class User{
    public:
        int id;
        Tweet* tweets;
        unordered_set<int> following;
        User(int id){
            this->id = id;
            this->tweets = nullptr;
            following.clear();
            follow(id);
            
        }
        
        void tweet(int ts, int id){
            Tweet* tweet = new Tweet(ts, id);
            tweet->next = this->tweets;
            this->tweets = tweet;
            return;
        }
        
        void follow(int followeeId){
            if(following.count(followeeId)) return;
            following.emplace(followeeId);
        }
        
        void unfollow(int followeeId){
            if(!following.count(followeeId) || followeeId == this->id) return;
            following.erase(followeeId);
        }
    };
    
    unordered_map<int, User*> allusers;
    int Cap;
    Twitter() {
        timestemp = 0;
        allusers.clear();
        Cap = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        if(!allusers.count(userId)){
            allusers[userId] = new User(userId);
        }
        
        allusers[userId]->tweet(timestemp++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if(!allusers.count(userId)) return res;
        struct comp{
            bool operator()(Tweet* a, Tweet* b){
                return a->t < b->t;
            }
        };
        priority_queue<Tweet*, vector<Tweet*>, comp> pq;
        for(int id : allusers[userId]->following){
            if(allusers[id]->tweets) pq.push(allusers[id]->tweets);
        }
        
        while(!pq.empty() && res.size() < Cap){
            Tweet* cur = pq.top();
            pq.pop();
            res.push_back(cur->id);
            if(cur->next) pq.push(cur->next);
        }
            
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(!allusers.count(followerId)){
            allusers[followerId] = new User(followerId);
        }
        
        if(!allusers.count(followeeId)){
            allusers[followeeId] = new User(followeeId);
        }
        
        allusers[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!allusers.count(followerId) || !allusers.count(followeeId)) return;
        allusers[followerId]->unfollow(followeeId);
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