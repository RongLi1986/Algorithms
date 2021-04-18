# 43. Multiply Strings

## Question link
(https://leetcode.com/problems/multiply-strings/description/)

## Question Description

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

## 解题思路

```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        string s = (num1.size() > num2.size()) ? num2 : num1;
        string l =  (num1.size() > num2.size()) ? num1 : num2;
        string res;
        string tmp;
        
        //simulate product algorithm
        for(int i = s.size() - 1; i >= 0; i--){
            int c = 0;
            int a = s[i] - '0';
            tmp.clear();
            for(int j = l.size() - 1; j >= 0; j--){
                int b =  l[j] - '0';
                int prod = (a * b + c) % 10;
                c = (a * b + c) / 10;
                tmp = to_string(prod) + tmp; 
            }
            if(c > 0) tmp = to_string(c) + tmp;
            res = addRes(res, tmp, s.size() - 1 - i);
        }
        
        return res;  

    }
    
    //simulate add
    string addRes(string s, string tmp, int index){
        for(int i = 0; i < index; i++){
            tmp = tmp + '0';
        }
        
        int c = 0;
        string res;
        
        int i = tmp.size()-1;
        int j = s.size() - 1;
        
        while(i >= 0 || j >= 0){
            int a = (i >= 0) ? tmp[i] - '0' : 0;
            int b = (j >= 0) ? s[j] - '0' : 0;
            int sum = (a + b + c) % 10;
            res = to_string(sum) + res;
            c = (a + b + c) / 10;
            i--;
            j--;
        }
        
        if(c > 0) res = to_string(c) + res;
        
        return res;
    }
};
```