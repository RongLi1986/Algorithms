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

class NewsFeed {
private:
    int time;
    Tweet tweet;
public:
    NewsFeed(Tweet tw,int t){
        time=t;
        tweet=tw;
    }
    
    //copy construct
    NewsFeed(const NewsFeed &nf){
        time=nf.getTime();
        tweet=nf.getTweet();
    }
    
    Tweet getTweet() const{
        return tweet;
    }
    
    int getTime() const{
        return time;
    }
}; 

//for priority_queue
class mycomparison{
public:
    mycomparison(){
        
    }
  
    bool operator() (const NewsFeed &lhs, const NewsFeed &rhs) {
        return lhs.getTime() < rhs.getTime();
    }
};
 
class MiniTwitter {
private:
    unordered_map<int, unordered_map<int,bool> > followedTable; //user_id, followedMap <other user id,                                                           
                                                                //friend flag>
    unordered_map<int, vector<NewsFeed> > newsTable;  //user_id, newsList
    int time;  //simulate time val;
    
public:
    MiniTwitter() {
        // initialize your data structure here.
        followedTable.clear();
        newsTable.clear();
        
        //reset time;
        time = 0; 
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        //create newsfeed
        Tweet tweet = Tweet::create(user_id,tweet_text);
        NewsFeed newsFeed(tweet,time);

        time++;
        
        if(newsTable.find(user_id) == newsTable.end()){
            newsTable[user_id] = vector<NewsFeed>();
        }
        
        newsTable[user_id].push_back(newsFeed);

        return tweet;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        vector<Tweet> res;
        priority_queue<NewsFeed, vector<NewsFeed>, mycomparison> tmp;
        
        
        /*
        pull model:
        each time, get NewsFeed from users and its follow users newsList (read)
        then, get 10 new feeds recently
        */
        //put self news
        if(newsTable.find(user_id) != newsTable.end()){
            int cnt=0;
            for(int i= newsTable[user_id].size()-1;i>=0;i--){
                tmp.push(newsTable[user_id][i]);
                cnt++;
                if(cnt>=10)
                    break;
            }
        }
        
        //put its followed Nodes
        if (followedTable.find(user_id) != followedTable.end()) {
            for (unordered_map<int, bool>::iterator it = followedTable[user_id].begin(); it != followedTable[user_id].end(); ++it){
                if (it->second) {
                    int user = it->first;
                    if (newsTable.find(user) != newsTable.end()) {
                        int cnt=0;
                        for(int i= newsTable[user].size()-1;i>=0;i--){
                            tmp.push(newsTable[user][i]);
                            cnt++;
                            if(cnt>=10)
                                break;
                        }
                    }
                }
            }
        }
        
        //pop 10 tweets
        int cnt = 0;
        int size =tmp.size();
        for(int i=0;i<size;i++){
            res.push_back(tmp.top().getTweet());
            tmp.pop();
            cnt++;
            if(cnt>=10)
                break;
        }
        
        return res;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        // Write your code here
        vector<Tweet> res;
        
        if(newsTable.find(user_id) != newsTable.end()){
            int cnt=0;
            for(int i= newsTable[user_id].size()-1;i>=0;i--){
                res.push_back(newsTable[user_id][i].getTweet());
                cnt++;
                if(cnt>=10)
                    break;
            }
        }
        
        return res;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        //cannot find users
        if(followedTable.find(from_user_id)==followedTable.end()){
            followedTable[from_user_id] = unordered_map<int,bool>();
        }
        
        followedTable[from_user_id][to_user_id] =true;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        //cannot find users
        if(followedTable.find(from_user_id)==followedTable.end())
            return;
        
        if(followedTable[from_user_id].find(to_user_id) == followedTable[from_user_id].end())
            return;
            
        followedTable[from_user_id][to_user_id] = false; 
    }
};

int main(){


	return 0;
}