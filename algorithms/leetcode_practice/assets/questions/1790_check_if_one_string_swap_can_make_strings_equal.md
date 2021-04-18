# 1790. Check if One String Swap Can Make Strings Equal

## Question link
(https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)

## Question Description
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

Example 1:

> Input: s1 = "bank", s2 = "kanb"
> Output: true
> Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:

> Input: s1 = "attack", s2 = "defend"
> Output: false
> Explanation: It is impossible to make them equal with one string swap.

Example 3:

> Input: s1 = "kelb", s2 = "kelb"
> Output: true
> Explanation: The two strings are already equal, so no string swap operation is required.

Example 4:

> Input: s1 = "abcd", s2 = "dcba"
> Output: false
 
Constraints:

- 1 <= s1.length, s2.length <= 100
- s1.length == s2.length
- s1 and s2 consist of only lowercase English letters.


## 分类 && 解题思路
string

## Code
```c++
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        
        vector<int> v = {};
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                v.push_back(i);
            }
        }
        
        return v.size() == 0 || (v.size() == 2 && s1[v[0]] == s2[v[1]] && s1[v[1]] == s2[v[0]]);
    }
};
```

## Time Complexity Analysis
Running time  : O(n)
running space : O(n)