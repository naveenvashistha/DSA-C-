#include <bits/stdc++.h>

using namespace std;

class Twitter {
public:
    unordered_map<int, unordered_set<int>> follower;
    unordered_map<int, vector<pair<int, int>>> tweets;
    long long time;
    Twitter() {
        time = 0;
    }
    //time: O(1)
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    //time: O(nlogn)
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto i: tweets[userId]) pq.push(i);
        for(auto i: follower[userId])
        {
            for(auto j: tweets[i]) pq.push(j);
        }
        int count = 10;
        vector<int> tweetIds;
        while(count != 0 && !pq.empty())
        {
            tweetIds.push_back(pq.top().second);
            pq.pop();
            count--;
        }
        return tweetIds;
    }
    //time: O(1)
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            follower[followerId].insert(followeeId);
    }
    //time: O(1)
    void unfollow(int followerId, int followeeId) {
            follower[followerId].erase(followeeId);
    }
};
int main()
{
}

