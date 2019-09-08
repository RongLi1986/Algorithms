/*
Memcache
Implement a memcache which support the following features:

get(curtTime, key). Get the key's value, return 2147483647 if key does not exist.
set(curtTime, key, value, ttl). Set the key-value pair in memcache with a time to live (ttl). The key will be valid from curtTime to curtTime + ttl - 1 and it will be expired after ttl seconds. if ttl is 0, the key lives forever until out of memory.
delete(curtTime, key). Delete the key.
incr(curtTime, key, delta). Increase the key's value by delta return the new value. Return 2147483647 if key does not exist.
decr(curtTime, key, delta). Decrease the key's value by delta return the new value. Return 2147483647 if key does not exist.
It's guaranteed that the input is given with increasingcurtTime.

get(1, 0)
>> 2147483647
set(2, 1, 1, 2)
get(3, 1)
>> 1
get(4, 1)
>> 2147483647
incr(5, 1, 1)
>> 2147483647
set(6, 1, 3, 0)
incr(7, 1, 1)
>> 4
decr(8, 1, 1)
>> 3
get(9, 1)
>> 3
delete(10, 1)
get(11, 1)
>> 2147483647
incr(12, 1, 1)
>> 2147483647

*/
#include <vector>

class Memcache {
private:
    unordered_map<int,pair<int,int> > hashMap; //<key, <value, expireTime>>
public:
    Memcache() {
        // initialize your data structure here.
        hashMap.clear();
    }

    int get(int curtTime, int key) {
        // Write your code here
        if(hashMap.find(key)==hashMap.end()){
            return INT_MAX;
        }else{
            if(hashMap[key].second == 0)
                return hashMap[key].first;
            if(curtTime > hashMap[key].second){
                return INT_MAX;
            }else{
                return hashMap[key].first;
            }
        }
    }

    void set(int curtTime, int key, int value, int ttl) {
        // Write your code here
        int expireTime = curtTime + ttl -1; 
        pair<int,int> tmp;
        if(ttl == 0)
            tmp=std::make_pair(value, 0);
        else
            tmp=std::make_pair(value, expireTime);
        hashMap[key] = tmp;
    }

    void del(int curtTime, int key) {
        // Write your code here
        hashMap.erase(key);
    }
    
    int incr(int curtTime, int key, int delta) {
        // Write your code here
        if(hashMap.find(key)==hashMap.end()){
            return INT_MAX;
        }else{
            if(hashMap[key].second == 0){
                hashMap[key].first +=delta;
                return hashMap[key].first;
            }
            if(curtTime > hashMap[key].second){
                return INT_MAX;
            }else{
                hashMap[key].first +=delta;
                return hashMap[key].first;
            }
        }
        
    }
    
    int decr(int curtTime, int key, int delta) {
        // Write your code here
        if(hashMap.find(key)==hashMap.end()){
            return INT_MAX;
        }else{
            if(hashMap[key].second == 0){
                hashMap[key].first -=delta;
                return hashMap[key].first;
            }
            if(curtTime > hashMap[key].second){
                return INT_MAX;
            }else{
                hashMap[key].first -=delta;
                return hashMap[key].first;
            }
        }
        
    }
};

int main(){

	return 0;
}