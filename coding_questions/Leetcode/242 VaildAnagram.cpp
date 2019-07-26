/*
Valid Anagram Total Accepted: 3672 Total Submissions: 9698 My Submissions Question Solution 
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

/*
one hashmap(or 256 integers array), travese all char in two string
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int map[256];   //ASIC II map
        
        for(int i=0;i<256;i++){
            map[i]=0;
        }
        
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(map[t[i]]<=0) 
                return false;
            else{
                map[t[i]]--;
            }
        }
        
        return true;
    }
};

class Solution_old {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<int, int> hash_map;
        for(int i=0;i<s.size();i++){
            if(hash_map.find(s[i])==hash_map.end()){
                hash_map[s[i]]=1;
            }else{
                hash_map[s[i]]+=1;
            }
        }
        
        for(int i=0;i<t.size();i++){
            if(hash_map.find(t[i])==hash_map.end()){
                return false;
            }else{
                if(hash_map[t[i]]==0)
                    return false;
                hash_map[t[i]]-=1;
            }
        }
        
        return true;
    }
};

int main(){
    Solution s;
    return 0;
}