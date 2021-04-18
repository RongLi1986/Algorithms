# 97. Interleaving String

## Question link
(https://leetcode.com/problems/interleaving-string/)

## Question Description
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

- s = s1 + s2 + ... + sn
- t = t1 + t2 + ... + tm
- |n - m| <= 1
- The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:

> ![Image](https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg)

> Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
> Output: true

Example 2:

> Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
> Output: false

Example 3:

> Input: s1 = "", s2 = "", s3 = ""
> Output: true
 
Constraints:
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lower-case English letters.

## 解题思路
dp

## Code
```c++
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 1));
        dp[0][0] = 1;
        
        for(int i = 1; i < dp.size(); i++){
            dp[i][0] = (dp[i-1][0] == 1 && s1[i - 1] == s3[i - 1]) ? 1 : 0;
        }
        
        for(int j = 1; j < dp[0].size(); j++){
            dp[0][j] = (dp[0][j - 1] == 1 && s2[j - 1] == s3[j - 1]) ? 1 : 0;
        }
        
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[i].size(); j++){
                dp[i][j] = (
                    (dp[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]) ||
                    (dp[i-1][j] == 1 && s1[i - 1] == s3[i + j - 1])
                ) ? 1 : 0;
            }
        }
        
        return dp[s1.size()][s2.size()];
    }
};
```

## Time Complexity Analysis
Running time  : O(n * m)
running space : O(n * m)