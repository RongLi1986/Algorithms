# 96. Unique Binary Search Trees

## Question link
(https://leetcode.com/problems/unique-binary-search-trees/)

## Question Description
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
![Image](https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg)

> Input: n = 3
> Output: 5

Example 2:

> Input: n = 1
> Output: 1

Constraints:

1 <= n <= 19

## 解题思路
dp

## Code
```c++
class Solution {
public:
    int numTrees(int n) {  
        vector<int> count(n + 1, 0);  
        count[0] = 1;  
        count[1] = 1;  
        
        for(int i = 2; i <= n; i++){  
            for(int j =0; j < i; j++){  
                //total cnt = left cnt * right cnt
                count[i] += count[j] * count[i - j - 1];
            }  
        }
        
        return count[n];  
    }  
};
```

## Time Complexity Analysis