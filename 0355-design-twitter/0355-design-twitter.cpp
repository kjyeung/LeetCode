class Tweet{
public:
    int id;
    int t;
    Tweet* next;
    
    Tweet(int _id, int _t){
        id = _id;
        t = _t;
        next = nullptr;
    }
};

class User{
public:
    int id;
    Tweet* tweets;
    unordered_set<int> following;
    
    User(int _id){
        id = _id;
        following.clear();
        tweets = nullptr;
        follow(_id);
    }
    
    void follow(int followeeid){
        if(following.count(followeeid)) return;
        following.insert(followeeid);
    }
    
    void unfollow(int followeeid){
        if(!following.count(followeeid) || followeeid == id) return;
        following.erase(followeeid);
        
    }
    
    void post(int tweetid, int t){
        Tweet* twt = new Tweet(tweetid, t);
        twt->next = tweets;
        tweets = twt;
    }
};
class Twitter {
private:
    unordered_map<int, User*> users;
    int timestamp;
    int cap = 10;

public:
    Twitter() {
        users.clear();
        timestamp = 0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(!users.count(userId)) users[userId] = new User(userId);
        users[userId]->post(tweetId, timestamp++);
        return; 
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ret;
        if(!users.count(userId)) return ret;
        struct comp{
            bool operator()(Tweet* a, Tweet*b){
                return a->t < b->t;
            }
        };
        priority_queue<Tweet*, vector<Tweet*>, comp> pq;
        for(int u : users[userId]->following){
            if(users[u]->tweets) pq.push(users[u]->tweets);
        }
        while(ret.size() < cap && !pq.empty()){
            Tweet* cur = pq.top();
            pq.pop();
            ret.push_back(cur->id);
            if(cur->next) pq.push(cur->next);
        }
        
        return ret;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(!users.count(followerId)) users[followerId] = new User(followerId);
        if(!users.count(followeeId)) users[followeeId] = new User(followeeId);
        users[followerId]->follow(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!users.count(followerId)) users[followerId] = new User(followerId);
        if(!users.count(followeeId)) users[followeeId] = new User(followeeId);
        users[followerId]->unfollow(followeeId);
        
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