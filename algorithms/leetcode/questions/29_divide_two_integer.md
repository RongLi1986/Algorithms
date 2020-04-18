# 29 Divide Two Integers

## Question link
(https://leetcode.com/problems/divide-two-integers/description/)

## Question Description

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

## 解题思路

```c++
class Solution {
public:
int divide(int dividend_int, int divisor_int) {
    	long long dividend = dividend_int;
    	long long divisor = divisor_int;

        if(divisor == 0) return INT_MAX;
        if(divisor == 1) return dividend;
        
        if(divisor == -1){
        	if(dividend == INT_MIN)
        		return ~(dividend);
        	return  ~(dividend) + 1;
        }

        //confirm sign
        int sign = 0;
        if((divisor < 0 && dividend > 0)||(divisor > 0 && dividend < 0)) 
            sign = 1;
        
        //cannot use abs() in here
        if(dividend < 0) dividend = 0 - dividend;
        if(divisor < 0) divisor = 0 - divisor;

        long long origDivsor = divisor;
        int res = 0;
        int count = 1;
        while(dividend >= origDivsor){
        	dividend = dividend-divisor;
        	res += count;
        	if(dividend >= (divisor<<1)){
        		divisor <<= 1; //*2
        		count <<= 1;  //*2
        	}else{
        		divisor = origDivsor;
        		count = 1;
        	}
        }
        
        return (sign == 0) ? res : ~res+1;
    }
};
```