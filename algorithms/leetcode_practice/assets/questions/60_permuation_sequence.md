# 60. Permutation Sequence

## Question link
(https://leetcode.com/problems/permutation-sequence/description/)

## Question Description

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"

## 解题思路
permuation problem

```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> s;
        for(int i = 1;i <= n;i++){
            s.push_back(i);
        }
        
        //kth means do loop (k -1) time
        for(int i = 0;i < k - 1; i++){
            nextPermutation(s);
        }
        
        string res;
        for(int i = 0;i < n; i++){
            res += to_string(s[i]);
        }
        
        return res;
    }
    
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        int changeIndex = -1;
        
        for(int i = size - 1;i > 0;i--){
            if(num[i] > num[i-1]){
                changeIndex = i - 1;
                for(int j = size - 1;j > changeIndex;j--){
                	if(num[j] > num[changeIndex]){
                        int tmp = num[changeIndex];
                        num[changeIndex] = num[j];
                        num[j] = tmp;
                		reverse(num.begin() + changeIndex + 1, num.end());
                        return;
                	}
                }
            }
        }
        
        if(changeIndex == -1)
            reverse(num.begin(),num.end());
       
        return;
    }
};
```