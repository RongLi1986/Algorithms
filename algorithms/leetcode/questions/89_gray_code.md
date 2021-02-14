# 89. Gray Code

## Question link
(https://leetcode.com/problems/gray-code/)

## Question Description
The gray code is a binary numeral system where two successive values differ in only one bit.

Given an integer n representing the total number of bits in the code, return any sequence of gray code.

A gray code sequence must begin with 0.

Example 1:

> Input: n = 2
> Output: [0,1,3,2]
> Explanation:
> 00 - 0
> 01 - 1
> 11 - 3
> 10 - 2
> [0,2,3,1] is also a valid gray code sequence.
> 00 - 0
> 10 - 2
> 11 - 3
> 01 - 1

Example 2:

> Input: n = 1
> Output: [0,1]

Constraints:
1 <= n <= 16

## 解题思路
dfs 
backtracking
bit manipulation

## Code
```c++
class Solution {
public:
    vector<int> grayCode(int n) {
        n = pow(2, n);

        vector<int> ans;
        
        ans.push_back(0);
        unordered_set<int> v;
        v.insert(0);
        
        dfs(n, ans, v);
        
        return ans;
    }
    
    void dfs(int n, vector<int>& ans, unordered_set<int>& v){
        if(v.size() == n){
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(v.find(i) == v.end() && differAtOneBitPos(ans.back(), i)){
                v.insert(i);
                ans.push_back(i);
                dfs(n, ans, v);
                if(v.size() == n) break;
                ans.pop_back();
                v.erase(i);
            }
        }
        
        return;
    }
               
    // function to check if x is power of 2 
    bool isPowerOfTwo(unsigned int x) 
    { 
        // First x in the below expression is 
        // for the case when x is 0 
        return x && (!(x & (x - 1))); 
    } 

    // function to check whether the two numbers 
    // differ at one bit position only 
    bool differAtOneBitPos(unsigned int a, 
                           unsigned int b) 
    { 
        return isPowerOfTwo(a ^ b); 
    } 
};
```

## Time Complexity Analysis
Running time  : O(n)
running space : O(n)