# 1763. Longest Nice Substring

## Question link
(https://leetcode.com/problems/longest-nice-substring/)

## Question Description
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

Example 1:

> Input: s = "YazaAay"
> Output: "aAa"
> Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
> "aAa" is the longest nice substring.

Example 2:

> Input: s = "Bb"
> Output: "Bb"
> Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.

Example 3:

> Input: s = "c"
> Output: ""
> Explanation: There are no nice substrings.

Example 4:

> Input: s = "dDzeE"
> Output: "dD"
> Explanation: Both "dD" and "eE" are the longest nice substrings.
> As there are multiple longest nice substrings, return "dD" since it occurs earlier.
 

Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.

## 解题思路
string

## Code
```c++
class Solution {
public:
    string longestNiceSubstring(string s) {
        int l = 0;
        string ret = "";
        
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(isNice(s.substr(i, j - i + 1))){
                    if(l < s.substr(i, j - i + 1).size()){
                        ret = s.substr(i, j - i + 1);
                        l = s.substr(i, j - i + 1).size();
                    }
                }
            }
        }
        
        return ret;
    }
    
    bool isNice(string s){
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(islower(s[i])){
                m[s[i]] = 0;
            }
        }
        
        for(int i = 0; i < s.size(); i++){
            if(isupper(s[i])){
                if(m.find(tolower(s[i])) != m.end()){
                    m[tolower(s[i])] = 1;
                }else{
                    return false;
                }
            }
        }
        
        for(auto itr = m.begin(); itr != m.end(); itr++){
            if(itr->second == 0){
                return false;
            }
        }
        
        return true;
    }
};
```

## Time Complexity Analysis
Running time  : O(n^2)
running space : O(n)