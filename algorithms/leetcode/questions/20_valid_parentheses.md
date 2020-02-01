# 20. Valid Parentheses

## Question link
(https://leetcode.com/problems/valid-parentheses/description/)

## Question Description
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"

## 解题思路

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char i:s){
        	if(i=='(' || i=='{' || i=='['){
        		st.push(i);
        	}else if(i==')' || i=='}' ||i==']'){
        		if(!st.empty()){
	        		if(st.top()=='(' && i==')')
	        			st.pop();
	        		else if(st.top() == '[' && i == ']')
	        			st.pop();
	        		else if(st.top() == '{'&& i == '}')
	        			st.pop();
	        		else
	        			return false;
        		}else{
        			return false;
        		}
        	}else{
        		return false; //inculded illegal char
        	}
        }

        return st.empty() ? true : false;
    }
};
```