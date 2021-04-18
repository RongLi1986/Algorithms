# 30 Substring with Concatenation of All Words

## Question link
(https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/)

## Question Description

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []

## 解题思路

```c++
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> target;
        vector<int> res;
        
        if(words.empty() || s.empty()) return res; 
        int count = 0;
        int wordLen = words[0].size();
        int wordNum = words.size();
        int strLen = s.size();
        
        if(wordLen * wordNum > strLen ) return res;
        for(int i = 0;i < words.size(); i++){
    			target[words[i]]++;
        }

        for(int i = 0; i < strLen - (wordLen * wordNum) + 1; i++){
            string substr(s, i, wordLen);
            if(target.find(substr) != target.end()){
                matchFunc(s, i, target, res, wordLen, wordNum);
            }
        }
        
        return res;
    }
    
    void matchFunc(string& s, int index, unordered_map<string, int> target, vector<int>& out, int wordLen, int wordNum){
        int i = 0;
        while(i < wordNum){
            string substr(s, index + i * wordLen, wordLen);
            if(target.find(substr) != target.end()){
                target[substr]--;
                if(target[substr] == 0) target.erase(substr);
            }
            i++;
        }
        
        if(target.empty()) out.push_back(index);
        return;
    }
};
```