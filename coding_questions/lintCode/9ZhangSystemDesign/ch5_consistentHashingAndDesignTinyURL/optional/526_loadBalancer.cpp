/*
Load Balancer 

Implement a load balancer for web servers. It provide the following functionality:

Add a new server to the cluster => add(server_id).
Remove a bad server from the cluster => remove(server_id).
Pick a server in the cluster randomly with equal probability => pick().

Example
At beginning, the cluster is empty => {}.

add(1)
add(2)
add(3)
pick()
>> 1         // the return value is random, it can be either 1, 2, or 3.
pick()
>> 2
pick()
>> 1
pick()
>> 3
remove(1)
pick()
>> 2
pick()
>> 3
pick()
>> 3
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class LoadBalancer {
private:
    set<int> cluster;
    int clusterNum;
public:
    LoadBalancer() {
        // Initialize your data structure here.
        cluster.clear();
        clusterNum = 0;
    }

    // @param server_id add a new server to the cluster 
    // @return void
    void add(int server_id) {
        // Write your code here
        cluster.insert(server_id);
        clusterNum++;
        return;
    }

    // @param server_id server_id remove a bad server from the cluster
    // @return void
    void remove(int server_id) {
        // Write your code here
        cluster.erase(server_id);
        clusterNum--;
        return;
    }

    // @return pick a server in the cluster randomly with equal probability
    int pick() {
        // Write your code here
        int pickNum = rand()%clusterNum;
        int ans = -1;
        for(auto itr = cluster.begin(); itr!=cluster.end(); ++itr){
            if(pickNum==0){
                ans = *itr;
                break;
            }
            pickNum--;
        }
        
        return ans;
        
    }
};