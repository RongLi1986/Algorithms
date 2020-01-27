# 7 Reverse Integer

## Question link
(https://leetcode.com/problems/reverse-integer/description/)

## Question Description
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


## 解题思路
mod each int and build result

```c++
class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while(x != 0){
            ans *= 10;
            ans += x%10;
            x = x/10;
        }
        
        return (ans>INT_MAX || ans<INT_MIN) ? 0 : ans;
    }
};
```