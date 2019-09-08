/*
LFU Cache 

LFU (Least Frequently Used) is a famous cache eviction algorithm.

For a cache with capacity k, if the cache is full and need to evict a key in it, the key with the lease frequently used will be kicked out.

Implement set and get method for LFU cache.

Have you met this question in a real interview? Yes
Example
Given capacity=3

set(2,2)
set(1,1)
get(2)
>> 2
get(1)
>> 1
get(2)
>> 2
set(3,3)
set(4,4)
get(3)
>> -1
get(2)
>> 2
get(1)
>> 1
get(4)
>> 4
*/
#include <vector>

class LFUCache{
private:
    vector<vector<int> > freqQueue;  //freq queue
    unordered_map<int, int> hashMap; //key, value
    unordered_map<int, int> FreqMap; //key, Freq
    int mCapacity;
    int count;
public:
    // @param capacity, an integer
    LFUCache(int capacity) {
        // Write your code here
        mCapacity = capacity;
        count = 0;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // Write your code here
        if(count < mCapacity){
            if(hashMap.find(key)==hashMap.end()){
                hashMap[key]=value;
                count++;
                
                vector<int> tmp;
                tmp.push_back(key);
                tmp.push_back(1);  //freq
                FreqMap[key] = 1;
                //insert new item into freqQueue
                insertFreq(freqQueue, tmp);
            }else{
                hashMap[key] = value;
                
                //update freq in queue
                updateFreq(freqQueue, key, FreqMap[key]);
                FreqMap[key] ++;
            }
        }else{
            if(hashMap.find(key)==hashMap.end()){
                if(hashMap.find(key)==hashMap.end()){
                    int deleteKey = findDeleteKey();
                    hashMap.erase(deleteKey);
                }
                hashMap[key] = value;
                //create a new node
                vector<int> tmp;
                tmp.push_back(key);
                tmp.push_back(1);   //freq
                FreqMap[key] = 1;
                //insert new item into freqQueue
                insertFreq(freqQueue, tmp);
            }else{
                hashMap[key] = value;
                
                //update freq in queue
                updateFreq(freqQueue, key, FreqMap[key]);
                FreqMap[key] ++;
            }
            
        }
        
        //printQueue();
        return;
    }
    
    // @return an integer
    int get(int key) {
        // Write your code here
        if(hashMap.find(key)==hashMap.end())
            return -1;
        int res= hashMap[key];
        
        updateFreq(freqQueue, key, FreqMap[key]);
        FreqMap[key] +=1;
        
        //printQueue();
        return res;
    }
    
    //insert node into queue with freq decending order
    void insertFreq(vector<vector<int>> &freqQueue, vector<int>& node){
        if(freqQueue.empty()){
            freqQueue.push_back(node);
            return;
        }
        
        //O(lgn)
        int index = searchInsert(freqQueue, node);
        freqQueue.insert(freqQueue.begin()+index,node);
        
        return;
    }
    
    //return key from end of queue, and delete queue last one
    int findDeleteKey( ){
        int res = freqQueue[freqQueue.size()-1][0];
        
        freqQueue.erase(freqQueue.end());
        
        return res;
    }
    
    //helper func update node freq and sort queue
    void updateFreq(vector<vector<int> > &freqQueue, int key, int freq){
        int nodeKey=0;
        int nodeFreq=0;
        int deleteIndex=0;
        
        //O(lgn)
        int index = binarySearch(freqQueue, freq);
        //cout<<index<<endl;
        for(int i=index ;i<freqQueue.size();i++){
            if(freqQueue[i][0] == key){
                nodeKey = freqQueue[i][0];
                nodeFreq = freqQueue[i][1];
                deleteIndex = i;
                break;
            }
        }
        
        
        /*
        //O(n)
        for(int i=0 ;i<freqQueue.size();i++){
            if(freqQueue[i][0] == key){
                nodeKey = freqQueue[i][0];
                nodeFreq = freqQueue[i][1];
                deleteIndex = i;
                break;
            }
        }
        */
        
        
        freqQueue.erase(freqQueue.begin() + deleteIndex);
        vector<int> node;
        node.push_back(nodeKey);
        node.push_back(nodeFreq+1);
        
        insertFreq(freqQueue, node);
        
        return;
    }
    
    
    int searchInsert(vector<vector<int> > &array, vector<int> &node) {
        
        int target = node[1];  //freq
        if(array.empty()) return 0;
        // write your code here
        int left=0;
        int right=array.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(array[mid][1]>target)
                left=mid+1;
            else
                right=mid-1;
        }
        
        if(right<0) return left;
        
        if(array[right][1]>target)
            return left;
        else
            return right;
    }
    
    
    int binarySearch(vector<vector<int> > &array, int freq) {
        // write your code here
        //cout<<"freq "<<freq<<endl;
        if(array.empty()) return -1;
        if(array[0][1]==freq) return 0;
        
        int left = 0;
        int right = array.size()-1;
        
        while(left+1<right){
            int mid=(left+right)/2;
            if(array[mid][1]>freq){
                left=mid;
            }else {
                right=mid;
            }
        }
        
        if(freq==array[right][1]){
            return right;
        }
        
        return -1;
    }
    
    void printQueue(){
        for(int i=0;i<freqQueue.size();i++){
            cout<<"("<<freqQueue[i][0]<<"-"<<freqQueue[i][1]<<") ";
        }
        cout<<endl;
        return;
    }
};
