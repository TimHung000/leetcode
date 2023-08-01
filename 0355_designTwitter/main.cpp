#include <unordered_map>
#include <set>
#include <vector>
#include <queue>

class Twitter {
private:    
   std::unordered_map<int, std::set<int>> followMap;
   std::unordered_map<int, std::vector<std::pair<int, int>>> tweetMap;
   long long time; 

public:
/** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must 
     *  be posted by users who the user followed or by the user herself. Tweets must be ordered from most
     *  recent to least recent. 
     * */
    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::tuple<int, int, int, int>> maxHeap;
        std::vector<int> res;

        followMap[userId].insert(userId);
        for (auto followeeIdPtr = followMap[userId].begin(); followeeIdPtr != followMap[userId].end(); ++followeeIdPtr) {
            if(tweetMap.find(*followeeIdPtr) != tweetMap.end()) {
                int index = tweetMap[*followeeIdPtr].size() - 1;
                int tweetTime = tweetMap[*followeeIdPtr][index].first;
                int tweetId = tweetMap[*followeeIdPtr][index].second;
                maxHeap.push({tweetTime, tweetId, *followeeIdPtr, index});
            }
        }

        while(!maxHeap.empty() && res.size() < 10) {
            auto item = maxHeap.top();
            maxHeap.pop();
            int tweetId = std::get<1>(item);
            int followeeId = std::get<2>(item);
            int index = std::get<3>(item);
            res.push_back(tweetId);
            if(index > 0) {
                int tweetTime = tweetMap[followeeId][index-1].first;
                int tweetId = tweetMap[followeeId][index-1].second;
                maxHeap.push({tweetTime, tweetId, followeeId, index-1});
            }
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};