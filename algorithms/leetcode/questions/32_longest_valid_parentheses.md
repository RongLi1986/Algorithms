# 32. Longest Valid Parentheses

## Question link
(https://leetcode.com/problems/longest-valid-parentheses/description/)

## Question Description

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"

## 解题思路

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack; // keep index
        int maxLen = 0;

        for (int i = 0; i < s.size(); ++i)
        {
           if(s[i]=='('){
              stack.push(i);
           }else{  //')'
               if(!stack.empty() && s[stack.top()] == '('){
                  int index = stack.top();
                  stack.pop();
                  int lastPos = stack.empty() ? -1 : stack.top(); //find last index from stack
                  maxLen = (maxLen <  i - lastPos ) ? i - lastPos : maxLen;
               }else{  
                  stack.push(i);
               }
           }
        }

        return maxLen;
    }
};

```