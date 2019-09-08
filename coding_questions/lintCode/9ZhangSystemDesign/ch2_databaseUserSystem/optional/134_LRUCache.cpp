/*
 Description
 Notes
 Testcase
 Judge
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists 
in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used 
item before inserting a new item.
*/

#include <vector>

class LRUCache{
private:
    unordered_map<int, int> hashMap;
    int mCapacity;
    int counter;
    vector<int > timeQueue;
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        mCapacity = capacity;
        counter = 0;
        timeQueue.clear();
        hashMap.clear();
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        if(mCapacity==0)
            return -1;
        if(hashMap.find(key)!=hashMap.end()){
            for(int i=0;i<timeQueue.size();i++){
                if(timeQueue[i]==key){
                    timeQueue.erase(timeQueue.begin()+i);
                    timeQueue.push_back(key);
                    break;
                }
            }
            
            //printTimeQueue();
            return hashMap[key];
        }else{
            //printTimeQueue();
            return -1;
        }
    }
    
    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if(mCapacity==0)
            return;
        if(hashMap.find(key) != hashMap.end()){
            hashMap[key] = value;
            for(int i=0;i<timeQueue.size();i++){
                if(timeQueue[i]==key){
                    timeQueue.erase(timeQueue.begin()+i);
                    timeQueue.push_back(key);
                    break;
                }
            }
            
        }else{
            hashMap[key] = value;
            if(counter < mCapacity){
                timeQueue.push_back(key);
                counter++;
            }else{
                hashMap.erase(timeQueue[0]);
                timeQueue.erase(timeQueue.begin());
                timeQueue.push_back(key);
            }
        }
        //printTimeQueue();
    }
    
    void printTimeQueue(){
        for(int i=0;i<timeQueue.size();i++){
            cout<<timeQueue[i]<<" ";
        }
        cout<<endl;
    }
};