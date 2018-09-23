/*
Implement a simple twitter. Support the following method:

postTweet(user_id, tweet_text). Post a tweet.
getTimeline(user_id). Get the given user's most recently 10 tweets posted by himself, order by timestamp from most recent to least recent.
getNewsFeed(user_id). Get the given user's most recently 10 tweets in his news feed (posted by his friends and himself). Order by timestamp from most recent to least recent.
follow(from_user_id, to_user_id). from_user_id followed to_user_id.
unfollow(from_user_id, to_user_id). from_user_id unfollowed to to_user_id.

postTweet(1, "LintCode is Good!!!")
>> 1
getNewsFeed(1)
>> [1]
getTimeline(1)
>> [1]
follow(2, 1)
getNewsFeed(2)
>> [1]
unfollow(2, 1)
getNewsFeed(2)
>> []
*/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

/*

*/ 

/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
 
class Node {
public:
    int order;
    Tweet tweet;
    Node(int o, Tweet t) {
        order = o, tweet = t;
    }

    bool operator < (const Node& o) const {
        return order > o.order;
    }
};

class MiniTwitter {
private:
    map<int, map<int, bool>> friends;
    map<int, vector<Node>> users_tweets;
    int order;

public:
    MiniTwitter() {
        // initialize your data structure here.
        order = 0;
        friends.clear();
        users_tweets.clear();
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        Tweet tweet = Tweet::create(user_id, tweet_text);
        if (users_tweets.find(user_id) == users_tweets.end())
            users_tweets[user_id] = vector<Node>();
        order += 1;
        users_tweets[user_id].push_back(Node(order, tweet));
        return tweet;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        vector<Node> tmp;
        if (users_tweets.find(user_id) != users_tweets.end())
            tmp = getTen(users_tweets[user_id]);
        
        if (friends.find(user_id) != friends.end()) {
            for (map<int, bool>::iterator it = friends[user_id].begin(); it != friends[user_id].end(); ++it)
            if (it->second) {
                int user = it->first;
                if (users_tweets.find(user) != users_tweets.end()) {
                    vector<Node> temp = getTen(users_tweets[user]);
                    for (Node node : temp)
                        tmp.push_back(node);
                }
            }
        } 
        sort(tmp.begin(), tmp.end());
        vector<Tweet> rt;
        for (int i = 0; i < tmp.size(); ++i) {
            if (i >= 10)
                break;
            rt.push_back(tmp[i].tweet);
        }
        return rt;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        // Write your code here
        vector<Node> tmp;
        if (users_tweets.find(user_id) != users_tweets.end())
            tmp = getTen(users_tweets[user_id]);
        sort(tmp.begin(), tmp.end());
        vector<Tweet> rt;
        for (int i = 0; i < tmp.size(); ++i) {
            if (i >= 10)
                break;
            rt.push_back(tmp[i].tweet);
        }
        return rt;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        if (friends.find(from_user_id) == friends.end())
            friends[from_user_id] = map<int, bool>();
        friends[from_user_id][to_user_id] = true;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        if (friends.find(from_user_id) == friends.end())
            return;
        if (friends[from_user_id].find(to_user_id) == friends[from_user_id].end())
            return;
        //friends[from_user_id].erase(friends[from_user_id][to_user_id]);
        friends[from_user_id][to_user_id] = false;
    }

    vector<Node> getTen(vector<Node> &tmp) {
        int cnt = 0;
        vector<Node> v1;
        int n = tmp.size();
        for (int i = n - 1; i >= 0; --i) {
            cnt += 1;
            v1.push_back(tmp[i]);
            if (cnt >= 10)
                break;
        }
        return v1;
    }
};


int main(){


	return 0;
}