# 1784. Check if Binary String Has at Most One Segment of Ones

## Question link
(https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)

## Question Description
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

Example 1:

> Input: s = "1001"
> Output: false
> Explanation: The ones do not form a contiguous segment.

Example 2:

> Input: s = "110"
> Output: true
 

Constraints:
1 <= s.length <= 100
s[i]​​​​ is either '0' or '1'.
s[0] is '1'.

## 解题思路
string

## Code
```c++
class Solution {
public:
    bool checkOnesSegment(string s) {
        int flag = -1;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1' && flag == -1){
                flag = 1;
            }else if(s[i] == '0' && flag == 1){
                flag = 0;
            }else if(s[i] == '1' && flag == 0){
                return false;
            }
        }
        
        return true;
    }
};
```

## Time Complexity Analysis
Running time  : O(n)
running space : O(1)