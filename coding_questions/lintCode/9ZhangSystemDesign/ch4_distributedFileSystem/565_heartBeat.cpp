/*
Heart Beat 

In the Master-Slave architecture, slave server will ping master in every k seconds 
to tell master server he is alive. If a master server didn't receive any ping 
request from a slave server in 2 * k seconds, the master will trigger an alarm 
(for example send an email) to administrator.

Let's mock the master server, you need to implement the following three methods:

initialize(slaves_ip_list, k). salves_ip_list is a list of slaves' ip addresses. 
k is define above.
ping(timestamp, slave_ip). This method will be called every time master received 
a ping request from one of the slave server. timestamp is the current timestamp 
in seconds. slave_ip is the ip address of the slave server who pinged master.
getDiedSlaves(timestamp). This method will be called periodically 
(it's not guaranteed how long between two calls). timestamp is the current 
timestamp in seconds, and you need to return a list of slaves' ip addresses that 
died. Return an empty list if no died slaves found.
You can assume that when the master started, the timestamp is 0, and every 
method will be called with an global increasing timestamp.

Example
initialize(["10.173.0.2", "10.173.0.3"], 10)
ping(1, "10.173.0.2")
getDiedSlaves(20)
>> ["10.173.0.3"]
getDiedSlaves(21)
>> ["10.173.0.2", "10.173.0.3"]
ping(22, "10.173.0.2")
ping(23, "10.173.0.3")
getDiedSlaves(24)
>> []
getDiedSlaves(42)
>> ["10.173.0.2"]
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class HeartBeat {
private:
    unordered_map<string, int> map; //ip,deadtime
    int mK;
public:

    HeartBeat() {
        // initialize your data structure here.
        map.clear();
    }

    // @param slaves_ip_list a list of slaves'ip addresses
    // @param k an integer
    // @return void
    void initialize(vector<string>& slaves_ip_list, int k) {
        // Write your code here
        mK = k;
        for(int i = 0;i<slaves_ip_list.size();i++){
            map[slaves_ip_list[i]] = 2 * mK;
        }
    }

    // @param timestamp current timestamp in seconds
    // @param slave_ip the ip address of the slave server
    // @return nothing
    void ping(int timestamp, string& slave_ip) {
        // Write your code here
        if(map.find(slave_ip) == map.end()) return;
        map[slave_ip] = timestamp + 2 * mK;
    }

    // @param timestamp current timestamp in seconds
    // @return a list of slaves'ip addresses that died
    vector<string> getDiedSlaves(int timestamp) {
        // Write your code here
        vector<string> res;
        
        for(auto itr = map.begin();itr!=map.end();++itr){
            if(itr->second<=timestamp)
                res.push_back(itr->first);
        }
        
        return res;
    }
};