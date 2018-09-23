/*
290. Word Pattern
Total Accepted: 20238 Total Submissions: 73860 Difficulty: Easy
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char,string> map;
    unordered_map<string, char> map1;
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.empty()||str.empty()) return false;
        
        unsigned int pos=0;
        unsigned int found=0;
        
        for(int i=0;i<pattern.size();i++){
            
            found = str.find(' ', pos);
            string word = str.substr(pos,found-pos);
            pos=found+1;

            if(map.find(pattern[i])==map.end()){ // new item insert
                if(map1.find(word)==map1.end()){
                    map[pattern[i]]=word;
                    map1[word]=pattern[i];
                }else
                    return false;
            }else{

                if(map[pattern[i]]!=word){
                    return false;
                }else{
                    if(map1[word]!=pattern[i])
                        return false;
                }
            }
        }
        
        if(pos!=0) return false; //str is longer than pattern

        return true;
    }
};

int main(){
	Solution s;
	cout<<s.wordPattern("abba", "dog cat cat dog")<<endl;

	return 0;
}