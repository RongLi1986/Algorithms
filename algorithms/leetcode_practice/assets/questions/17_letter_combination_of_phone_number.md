# 17. Letter Combinations of a Phone Number

## Question link
(https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)

## Question Description
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 ![Image](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.

## 解题思路
dfs + backtracking

```c++
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> ans;
        string tmp;
        if(digits.empty()) return ans;
        
        dfs(digits, 0, tmp, ans, m);
            
        return ans;
    }
    
    void dfs(string& digits, int index, string& tmp, vector<string>& ans, vector<string>& m){
        if(index == digits.size()){
            ans.push_back(tmp);
            return;
        }
        
        string s = m[digits[index]  - '2'];
        
        for(int i = 0;i < s.size(); i++){
            tmp += s[i];
            dfs(digits, index + 1, tmp, ans, m);
            tmp.pop_back();
        }
        
        return;
    }
};
```