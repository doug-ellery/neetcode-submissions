struct max_heap_item{
    int userId, count, tweetId, idx;
    max_heap_item(int uid, int c, int twid, int indx) : userId(uid), count(c), tweetId(twid), idx(indx){}
};
struct maxHeapOp{
    bool operator()(max_heap_item a, max_heap_item b){
        return a.count < b.count;
    }
};

class Twitter {
private:
    unordered_map<int, unordered_set<int>> user_to_following;
    unordered_map<int, vector<pair<int,int>>> user_to_posts;
    int count;
public:
    Twitter() {
        this->count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user_to_posts[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<max_heap_item, vector<max_heap_item>, maxHeapOp> max_heap;
        vector<int> feed;
        user_to_following[userId].insert(userId);
        for(const auto& followee : user_to_following[userId]){
            const auto& posts = user_to_posts[followee];
            if(posts.empty()){continue;}
            int uid = followee;
            int cnt = posts.back().first;
            int tweetId = posts.back().second;
            int idx = posts.size() - 1;
            max_heap.push(max_heap_item(uid, cnt, tweetId, idx));
        }
        user_to_following[userId].erase(userId);
        for(int i = 0; i < 10; i++){
            if(max_heap.empty()){break;}
            const auto item = max_heap.top();
            max_heap.pop();
            feed.push_back(item.tweetId);
            if(item.idx > 0){
                const auto& posts = user_to_posts[item.userId];
                int idx = item.idx - 1;
                int uid = item.userId;
                int cnt = posts[idx].first;
                int tweetId = posts[idx].second;
                max_heap.push(max_heap_item(uid, cnt, tweetId, idx));
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        user_to_following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        user_to_following[followerId].erase(followeeId);
    }
};
