class Tweet{
public:
    int id;
    int ts;
    Tweet* next;
    Tweet(int _id, int _ts): id(_id), ts(_ts), next(nullptr){}
};

class User{
public:
    int id;
    unordered_set<int> following;
    Tweet* tweets;
     User(int userid){
         id = userid;
         tweets = nullptr;
         follow(userid);
     }
    
    void follow(int userid){
        if(following.count(userid)) return;
        following.insert(userid);
        return;
    }
    
    void unfollow(int userid){
        if(!following.count(userid) || userid == this->id) return;
        following.erase(userid);
        return;
    }
    
    void tweet(int tweetid, int timestemp){
        Tweet* cur = new Tweet(tweetid, timestemp);
        cur->next = tweets;
        tweets = cur;
        return;
    }
    
};

class Twitter {
public:
    int timestemp;
    unordered_map<int, User*> alluser;
    int cap = 10;
    
    Twitter() {
        timestemp = 0;
        alluser.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        if(!alluser.count(userId)){
            alluser[userId] = new User(userId);
        }
        alluser[userId]->tweet(tweetId, timestemp++);
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        struct comp{
            bool operator()(Tweet* a, Tweet* b){
                return a->ts < b->ts;
            }
        };
        vector<int> res;
        priority_queue<Tweet*, vector<Tweet*>, comp> pq;
        if(!alluser.count(userId)) return res;
        
        for(int uid : alluser[userId]->following){
            User* cur = alluser[uid];
            if(cur->tweets)  pq.push(cur->tweets);
        }
        
        while(res.size() < cap && !pq.empty()){
            Tweet* cur = pq.top();
            pq.pop();
            res.push_back(cur->id);
            if(cur->next){
                pq.push(cur->next);
            }
        }
        
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(!alluser.count(followerId)){
            alluser[followerId] = new User(followerId);
        }
        if(!alluser.count(followeeId)){
            alluser[followeeId] = new User(followeeId);
        }
        alluser[followerId]->follow(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!alluser.count(followerId) || !alluser.count(followeeId)) return;
        alluser[followerId]->unfollow(followeeId);
        return;
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