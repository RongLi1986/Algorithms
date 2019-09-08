/*
Standard Bloom Filter 

Implement a standard bloom filter. Support the following method:
1. StandardBloomFilter(k),The constructor and you need to create k hash functions.
2. add(string). add a string into bloom filter.
3. contains(string). Check a string whether exists in bloom filter.

Have you met this question in a real interview? Yes
Example
StandardBloomFilter(3)
add("lint")
add("code")
contains("lint") // return true
contains("world") // return false
*/



#include <iostream>

class StandardBloomFilter {
private:
    unordered_map<string ,int> map;
public:
    StandardBloomFilter(int k) {
        // initialize your data structure here
        map.clear();
    }

    void add(string& word) {
        // Write your code here
        map[word] = 1;
        return;
    }

    bool contains(string& word) {
        // Write your code here
        return map.find(word)!=map.end();
    }
};