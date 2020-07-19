class Twitter {
private:
    int cnt;
    vector<<pair<int, int>> message;
    unordered_map<int, unordered_set<int>> dict;
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        message.push_back({userId, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int i = message.size() - 1;
        vector<int> res;
        int count = 0;
        while(i >= 0 && count < 10)
        {
            if(dict[userId].find(message[i].first) != dict[userId].end())
            {
                count++;
                res.push_back(tweetId);
            }
            i--;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        dict[followerId].add(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        dict[followerId].erase(followeeId);
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