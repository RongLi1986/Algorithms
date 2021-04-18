# 69 Sqrt(x)

## Question link
(https://leetcode.com/problems/sqrtx/description/)

## Question Description

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.

## 解题思路
binary search

```c++
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        double up = x;
        double down = 0;
        double temp = 0;

        while(up - down > 1e-6){
            temp = (up + down)/2;
            if((int)(temp * temp) > x){
                up = temp;
            }else{
                down = temp;
            }
        }

        return (int)temp;
    }
};
```