# 1796. Second Largest Digit in a String

## Question link
(https://leetcode.com/problems/second-largest-digit-in-a-string/)

## Question Description
Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
An alphanumeric string is a string consisting of lowercase English letters and digits.

Example 1:

> Input: s = "dfa12321afd"
> Output: 2
> Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.

Example 2:

> Input: s = "abc1111"
> Output: -1
> Explanation: The digits that appear in s are [1]. There is no second largest digit. 
 
Constraints:
- 1 <= s.length <= 500
- s consists of only lowercase English letters and/or digits.

## 分类 && 解题思路
string

## Code
```c++
class Solution {
public:
    int secondHighest(string s) {
        int first = -1;
        int second = -1;
        unordered_set<int> m;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                if(first == s[i] - '0' || second == s[i] - '0') continue;
                if(first < s[i] - '0'){
                    second = first;
                    first = s[i] - '0';
                }else if(second < s[i] - '0'){
                    second = s[i] - '0';
                }
                m.insert(s[i] - '0');
            }
        }
        
        return second;
    }
};
```

## Time Complexity Analysis
Running time  : O(n)
running space : O(1)