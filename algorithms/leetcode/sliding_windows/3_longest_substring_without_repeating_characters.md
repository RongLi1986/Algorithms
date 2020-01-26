# 3. Longest Substring Without Repeating Characters

## Question link
(https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

## Question Description
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring

## 解题思路

use Hashtable to store the characters in current window [start, end)
Then we slide end index to the right. If it is not in the HashSet, we slide end further. 
Doing so until s[end] is already in the HashSet. 
At this point, we found the maximum size of substrings without duplicate characters start with index ii.

Time complexity : O(2n) = O(n)O(2n)=O(n)
Space complexity : O(k) (k is size of hashtable)
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256] = {0};
        int begin =0, end = 0, conflict = 0, res = 0;
        
        while(end<s.size()){
            char c = s[end];
            hash[c]++;
            if(hash[c]>1) conflict++;
            end++;
            
            while(conflict > 0){ //find repeat
                char ctemp = s[begin];
                if(hash[ctemp]>1)
                    conflict--;
                hash[ctemp]--;
                begin++;
            }
            
            res = max(res, end- begin);
        }
        
        return res;
    }
};
```