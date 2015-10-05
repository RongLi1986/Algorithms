/*
Isomorphic Strings Total Accepted: 696 Total Submissions: 2950 My Submissions Question Solution 
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

/*
it need two maps(hashmap or array), map1 is mappng string s to t, 
and map2 is mapping string t to s. then scan string, 

for two chars
if s[i] and t[i] is no map, build the mapping in two maps.
else 
    if map1[s[i]]!=t[i] or map2[t[i]]!=s[i], return false;

if pass the scan, return true
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution_hasmap {
private:
    unordered_map<char, char> hashmap1;
    unordered_map<char, char> hashmap2;
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;

        for(int i=0;i<s.size();i++){
            if(hashmap1.find(s[i])==hashmap1.end()){
                hashmap1[s[i]]=t[i];
            }else{
                if(hashmap1[s[i]]!=t[i])
                    return false;
            }
        }


        for(int i=0;i<s.size();i++){
            if(hashmap2.find(t[i])==hashmap2.end()){
                hashmap2[t[i]]=s[i];
            }else{
                if(hashmap2[t[i]]!=s[i])
                    return false;
            }
        }

        return true;
    }
};


class Solution { //use C array  faster
private:
    int  hashmapS[256];
    int  hashmapT[256];
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;

        for(int i=0;i<256;i++){
            hashmapS[i]=-1;
            hashmapT[i]=-1;
        }

        for(int i=0;i<s.size();i++){
            if(hashmapS[s[i]]==-1){
                if(hashmapT[t[i]]==-1){
                    hashmapS[s[i]]=t[i];
                    hashmapT[t[i]]=1;
                }else{
                    return false;
                }
            }else{
                if(hashmapS[s[i]]!=t[i])
                    return false;
            }
        }



        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isIsomorphic("13","11")<<endl;

	return 0;
}