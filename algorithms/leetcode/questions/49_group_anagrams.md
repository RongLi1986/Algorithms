# 49. Group Anagrams

## Question link
(https://leetcode.com/problems/group-anagrams/description/)

## Question Description

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.


## 解题思路


```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > m;
        for(int i=0;i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            if(m.find(key) == m.end()){
                vector<string> tmp;
                m[key] = tmp;
            }
            
            m[key].push_back(strs[i]);
        }
        
        for(auto itr = m.begin();itr!=m.end();itr++){
            res.push_back(itr->second);
        }
        
        return res;
    }
};
```