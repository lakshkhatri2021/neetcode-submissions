class Twitter {
    unordered_map<int, vector<pair<int, int>>> user;
    int time = 0;
    unordered_map<int, unordered_set<int>> follows;

   public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        user[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> tweets;
        for (auto t : user[userId]) {
            tweets.push(t);
        }

        for (auto f : follows[userId]) {
            for (auto t : user[f]) {
                tweets.push(t);
            }
        }

        vector<int> top10;

        while (!tweets.empty() && top10.size() < 10) {
            pair<int, int> tweet = tweets.top();
            tweets.pop();
            top10.push_back(tweet.second);
        }
        return top10;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) { follows[followerId].erase(followeeId); }
};
