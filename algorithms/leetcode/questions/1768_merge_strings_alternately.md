# 1768. Merge Strings Alternately

## Question link
(https://leetcode.com/problems/merge-strings-alternately/)

## Question Description
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:
> Input: word1 = "abc", word2 = "pqr"
> Output: "apbqcr"
> Explanation: The merged string will be merged as so:
> word1:  a   b   c
> word2:    p   q   r
> merged: a p b q c r

Example 2:
> Input: word1 = "ab", word2 = "pqrs"
> Output: "apbqrs"
> Explanation: Notice that as word2 is longer, "rs" is appended to the end.
> word1:  a   b 
> word2:    p   q   r   s
> merged: a p b q   r   s

Example 3:
> Input: word1 = "abcd", word2 = "pq"
> Output: "apbqcd"
> Explanation: Notice that as word1 is longer, "cd" is appended to the end.
> word1:  a   b   c   d
> word2:    p   q 
> merged: a p b q c   d

Constraints:
- 1 <= word1.length, word2.length <= 100
- word1 and word2 consist of lowercase English letters.

## 分类 && 解题思路
string

## Code
```c++
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string ret;
        while(i < word1.size() && j < word2.size()){
            if(i <= j){
                ret += word1[i];
                i++;
            }else{
                ret += word2[j];
                j++;
            }
        }
        
        if(word1.size() > word2.size()){
            ret += word1.substr(i);
        }else{
            ret += word2.substr(j);
        }
        
        return ret;
    }
};
```

### Time Complexity Analysis
Running time  : O(n)
running space : O(n)