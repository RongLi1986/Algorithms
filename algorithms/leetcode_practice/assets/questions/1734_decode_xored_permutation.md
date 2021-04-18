# 1734. Decode XORed Permutation

## Question link
(https://leetcode.com/problems/decode-xored-permutation/)

## Question Description

There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.


Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]

Example 2:

Input: encoded = [6,5,4,6]
Output: [2,4,1,5,3]
 

Constraints:

3 <= n < 105
n is odd.
encoded.length == n - 1

##
array + XOR


```c++
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        //find first number (Why?)
        int x = 0;
        for(int i = 1; i <= encoded.size() + 1; i++){
            x ^= i;
        }
        
        int f = x;
        for(int i = 1; i < encoded.size(); i+=2){
            f ^= encoded[i];
        }
        
        // Got first number
        vector<int> ans = {f};
        for(int i = 0; i < encoded.size(); i++){
            int a = ans.back();
            int c = encoded[i];
            int b = c ^ a;
            ans.push_back(b);
        }
        
        return ans;
    }
};
```