# 9 Palindrome Number

## Question link
(https://leetcode.com/problems/palindrome-number/description/)

## Question Description
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?


## 解题思路
reverse number and compare with before value
Time Complexity: O(1)
Space Complexity: O(1)

```c++
class Solution {
public:
    bool isPalindrome(int x) {
        return (x >= 0) && x == reverse(x);
    }

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