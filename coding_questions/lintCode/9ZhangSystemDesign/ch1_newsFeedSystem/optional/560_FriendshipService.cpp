/*
Friendship Service 

Support follow & unfollow, getFollowers, getFollowings.

Have you met this question in a real interview? Yes
Example
follow(1, 3)
getFollowers(1) // return [3]
getFollowings(3) // return [1]
follow(2, 3)
getFollowings(3) // return [1,2]
unfollow(1, 3)
getFollowings(3) // return [2]
*/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

class FriendshipService {
private:
    unordered_map<int, set<int> > followerMap; //id, followerlist //zui id
    unordered_map<int, set<int> > followingMap; //id, followinglist //id zui
public:
    FriendshipService() {
        // initialize your data structure here.
        followerMap.clear();
        followingMap.clear();
    }
        
    // @param user_id an integer
    // return all followers and sort by user_id
    vector<int>  getFollowers(int user_id) {
        // Write your code here
        vector<int> res;
        if(followerMap.find(user_id) == followerMap.end())
            return res;
        
        for(auto itr =followerMap[user_id].begin();
            itr!=followerMap[user_id].end();itr++){
            res.push_back(*itr);
        }
        
        sort(res.begin(), res.end());
        
        return res;
        
    }

    // @param user_id an integer
    // return all followings and sort by user_id
    vector<int>  getFollowings(int user_id) {
        // Write your code here
        vector<int> res;
        if(followingMap.find(user_id) == followingMap.end())
            return res;
        
        for(auto itr =followingMap[user_id].begin();
            itr!=followingMap[user_id].end();itr++){
            res.push_back(*itr);
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        if(followerMap.find(from_user_id) == followerMap.end()){
            set<int> s;
            followerMap[from_user_id] = s;
        }
        followerMap[from_user_id].insert(to_user_id);
        
        
        if(followingMap.find(to_user_id) == followingMap.end()){
            set<int> s;
            followingMap[to_user_id] = s;
        }
        followingMap[to_user_id].insert(from_user_id);
        
        
        return;
        
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        if(followerMap.find(from_user_id) == followerMap.end()){
            
        }else{
            followerMap[from_user_id].erase(to_user_id);
        }
        
        if(followingMap.find(to_user_id) == followingMap.end()){
            
        }else{
            followingMap[to_user_id].erase(from_user_id);
        }
        
        return;
    }
};