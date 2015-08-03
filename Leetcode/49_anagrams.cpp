/*
Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
use a hashmap, sort string as key and index as vector
travese this input, if find  item has same key's with hashmap's, 
push it in result vector, and push hasmap item in a tmp vector. 
finally push vector item (should avoid repeat item) into result's vector.
*/


class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> out;
        unordered_map<string,int> myMap;  //key is string, and value is its index in vector
        vector<int> index;
        for(int i=0;i<strs.size();i++){
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(myMap.find(tmp)==myMap.end()){
                myMap[tmp]=i;
            }else{
                out.push_back(strs[i]);
                index.push_back(myMap[tmp]);
            }
        }

        if(!index.empty()){
            for(int i=0;i<index.size();i++){
                sort(index.begin(),index.end());
                while(i<index.size()-1&& index[i]==index[i+1]) i++;
                out.push_back(strs[index[i]]);
            }
        }

        return out;
    }
};


int main(){
    vector<string> strs;
    strs.push_back("abc");
    strs.push_back("bca");
    strs.push_back("bba");
    strs.push_back("abb");
    strs.push_back("bab");

    Solution s;
    vector<string> out=s.anagrams(strs);

    for(int i=0;i<out.size();i++){
        cout<<out[i]<<endl;
    }

    return 0;

}