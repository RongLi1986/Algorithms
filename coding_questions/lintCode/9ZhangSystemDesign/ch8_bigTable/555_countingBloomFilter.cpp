/*
Counting Bloom Filter 

Implement a counting bloom filter. Support the following method:
1. add(string). Add a string into bloom filter.
2. contains(string). Check a string whether exists in bloom filter.
3. remove(string). Remove a string from bloom filter.

Have you met this question in a real interview? Yes
Example
CountingBloomFilter(3) 
add("lint")
add("code")
contains("lint") // return true
remove("lint")
contains("lint") // return false
Tags 
*/



#include <iostream>

class CountingBloomFilter {
private:
    unordered_map<string, int> map;
public:
    CountingBloomFilter(int k) {
        // initialize your data structure here
        map.clear();
    }

    void add(string& word) {
        // Write your code here
        if(map.find(word) == map.end()){
            map[word] = 1;
        }else{
            map[word] ++;    
        }
    }

    void remove(string& word) {
        // Write your code here
        if(map.find(word) == map.end()) return;
        
        map[word]--;
        
        if(map[word]==0)
            map.erase(word);
            
        return;
    }
    bool contains(string& word) {
        // Write your code here
        return map.find(word) != map.end();
    }
};