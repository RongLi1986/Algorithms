# 5. Longest Palindromic Substring

## Question link
(https://leetcode.com/problems/longest-palindromic-substring/description/)

## Question Description
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

## 解题思路
dp(i, j) represents whether s(i ... j) can form a palindromic substring, 
dp(i, j) is true when s(i) equals to s(j) and s(i+1 ... j-1) is a palindromic substring. 
When we found a palindrome, check if it’s the longest one. 

Time complexity O(n^2)
Space complexity O(n^2)

```c++
class Solution {
public:     
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int start = 0;
        int end = 0;
        int len = 1;

        //one char is always palindrome
        for(int i = 0;i < s.size();i++){
            for(int j = 0;j < i+1;j++){
                dp[i][j] = 1;
            }
        }

        for(int i = s.size() - 1;i >= 0;i--){
            for(int j = i + 1;j < s.size();j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                    if(dp[i][j] ==1 && j - i + 1 > len){
                        len = j - i + 1;
                        start = i;
                        end = j;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        /*
         for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
         }
         */

        return s.substr(start,end-start+1);
    }
};
```