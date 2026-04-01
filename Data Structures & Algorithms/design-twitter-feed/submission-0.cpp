class comp{
    public:
    bool operator()(vector<int> &a,vector<int> &b){
        return a[0] < b[0];
    }
};

class Twitter {
    unordered_map<int,set<int>> followMap;
    unordered_map<int,vector<pair<int,int>>> tweetMap;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // timestamp,tweetid,user,index
        priority_queue<vector<int>,vector<vector<int>>,comp> mostRecent;
        followMap[userId].insert(userId);
        for(auto user:followMap[userId]){
            if(tweetMap.count(user)){
                int index = tweetMap[user].size() - 1;
                auto [timestamp,tweetId] = tweetMap[user][index];
                mostRecent.push({timestamp,tweetId,user,index});

            }
            
        }
        vector<int> ans;
        while(!mostRecent.empty() && ans.size() < 10 ){
            auto top = mostRecent.top();
            mostRecent.pop();
            int timestamp = top[0];
            int tid       = top[1];
            int user      = top[2];
            int index     = top[3];

            ans.push_back(tid);

            if (index > 0) {
                auto [prevTime, prevTid] = tweetMap[user][index - 1];
                mostRecent.push({prevTime, prevTid, user, index - 1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId)){
            followMap[followerId].erase(followeeId);
        }
    }
};
