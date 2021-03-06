# 28. Implement strStr()

## Question link
(https://leetcode.com/problems/implement-strstr/description/)

## Question Description

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

## 解题思路

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int i = 0;
        while(i < haystack.size()){
            if(haystack.size() - i < needle.size())
                return -1;
            int j = 0;
            int k = i;
            while(haystack[k] == needle[j]){
                if(j == needle.size() - 1) return i;
                j++;
                k++;
            }
            i++;
        }

        return -1;
    }
};
```