# 65. Valid Number

## Question link
(https://leetcode.com/problems/valid-number/description/)

## Question Description

Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

## 解题思路
states && math

```c++
class Solution {
private:
    enum InputType {  
            INVALID,       // 0 Include: Alphas, '(', '&' ans so on  
            SPACE,         // 1  
            SIGN,          // 2 '+','-'  
            DIGIT,         // 3 numbers  
            DOT,           // 4 '.'  
            EXP,           // 5 'e' 'E'  
    };  
    int const stateMachineTable[5][9]={
        {0,8,-1,-1,8,-1,8,8,8},
        {3,-1,-1,-1,-1,6,-1,-1,-1},
        {1,1,4,1,4,7,7,7,-1},
        {2,4,-1,2,-1,-1,-1,-1,-1},
        {-1,5,-1,-1,5,-1,-1,-1,-1},
    };

public:
    bool isNumber(string s) {
        if(s.size() == 0) return false;
        int current = 0;
        int input;
        for(int i=0;i<s.size();i++){
            if(current==-1) return false;
            
            if(s[i]==' '){ //space
                input = 0;
            }else if(s[i]=='+'||s[i]=='-'){ //sign
                input = 1;
            }else if(s[i]-'0'>=0 && s[i]-'0'<=9){ //digit
                input = 2;
            }else if(s[i]=='.'){//dot
                input = 3;
            }else if(s[i]=='e'||s[i]=='E'){
                input = 4;
            }else{
                return false;
            }

            current = stateMachineTable[input][current];
        }

        if(current == 1 || current == 4 ||current == 7 ||current == 8)
            return true;
        else
            return false;
    }
};
```