# 1832. Check if the Sentence Is Pangram

## Question link
(https://leetcode.com/problems/check-if-the-sentence-is-pangram/)

## Question Description
A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Example 1:

> Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
> Output: true
> Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:

> Input: sentence = "leetcode"
> Output: false

Constraints:
- 1 <= sentence.length <= 1000
- sentence consists of lowercase English letters.

## 分类 && 解题思路
string
array

## Code
```c++
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> m(26, 0);
        for(int i = 0; i < sentence.size(); i++){
            m[sentence[i]-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(m[i] == 0) return false;
        }
        
        return true;
    }
};
```

## Time Complexity Analysis
Running time  : O(n)
running space : O(1)