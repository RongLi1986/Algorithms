/*
Rate Limiter 

Implement a rate limiter, provide one method: is_ratelimited(timestamp, event, 
rate, increment).

timestamp: The current timestamp, which is an integer and in second unit.
event: The string to distinct different event. for example, "login" or "signup".
rate: The rate of the limit. 1/s (1 time per second), 2/m (2 times per minute), 10/h (10 times per hour), 100/d (100 times per day). The format is [integer]/[s/m/h/d].
increment: Whether we should increase the counter. (or take this call as a hit of the given event)
The method should return true or false to indicate the event is limited or not.

Have you met this question in a real interview? Yes
Example
is_ratelimited(1, "login", "3/m", true), return false.
is_ratelimited(11, "login", "3/m", true), return false.
is_ratelimited(21, "login", "3/m", true), return false.
is_ratelimited(30, "login", "3/m", true), return true.
is_ratelimited(65, "login", "3/m", true), return false.
is_ratelimited(300, "login", "3/m", true), return false.
*/



#include <iostream>

class RateLimiter {
private:
    unordered_map<string, map<int, int>> mp;
public:
    /**
     * @param timestamp the current timestamp
     * @param event the string to distinct different event
     * @param rate the format is [integer]/[s/m/h/d]
     * @param increment whether we should increase the counter
     * @return true or false to indicate the event is limited or not
     */
    bool isRatelimited(int timestamp, string& event, string& rate, bool increment) {
        // Write your code here
        int start = rate.find("/");
        int total_time = atoi(rate.substr(0, start).c_str());
        string type = rate.substr(start + 1, rate.size() - start -1);

        int time = 1;
        if (type == "m")
            time = time * 60;
        else if (type == "h")
            time = time * 60 * 60;
        else if (type == "d")
            time = time * 60 * 60 * 24;
        int last_time = timestamp - time + 1;
        
        if (mp.find(event) == mp.end()) {
            mp[event] = map<int, int>();
        }

        bool rt = find_event(mp[event], last_time) >= total_time;
        if (increment && !rt)
            insert_event(mp[event], timestamp);
        return rt;
    }

    void insert_event(map<int, int> &event, int timestamp) {
        if (event.find(timestamp) != event.end())
            event[timestamp] += 1;
        else
            event.insert(make_pair(timestamp, 1));
    }

    int find_event(map<int, int> &event, int last_time) {
        int ans = 0;
        for (map<int, int>::iterator it = event.lower_bound(last_time); 
                it != event.end(); it++) {
            if (it->first >= last_time)
                ans += it->second;
            else
                break;
        }
        return ans;
    }
};