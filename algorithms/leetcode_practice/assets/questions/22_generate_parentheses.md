# 22. Generate Parentheses

## Question link
(https://leetcode.com/problems/generate-parentheses/description/)

## Question Description
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

## 解题思路
dfs + backtracking

```c++
class Solution {
public:
     vector<string> generateParenthesis(int n) {
        string s;
        vector<string> out;
        getParenthesis_new(n, n, s, out);
        return out;
    }

    void getParenthesis_new(int left, int right, string s, vector<string>& out){
        if(left < 0 || right < left) return;  //illegal case

        if(left == 0 && right == 0){
            out.push_back(s);
        }else{
            string l = s;
            l += "(";
            getParenthesis_new(left -  1, right, l, out);
            
            if(right > left){
                string r = s;
                r += ")";
                getParenthesis_new(left, right - 1, r, out);
            }
        }
        
        return;
    }
};
```