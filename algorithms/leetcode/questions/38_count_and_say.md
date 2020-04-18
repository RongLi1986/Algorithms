# 38. Count and Say

## Question link
(https://leetcode.com/problems/count-and-say/description/)

## Question Description

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" w

## 解题思路

```c++
class Solution {
public:
    string countAndSay(int n) {
        
        //recursive find n -1 answer
        if(n == 1) return "1";
        string ans = countAndSay(n-1);
        
        //conduct to n's answer
        ans += '0';
        int lastPos = -1;
        string ret = "";
        char c;
        for(int i = 0; i < ans.size()-1; i++){
            if(i < ans.size() -1 && ans[i] != ans[i+1] ){
                ret += to_string(i - lastPos);
                ret += ans[i];
                lastPos = i;
            }
        }
        
        return ret;
    }
};
```