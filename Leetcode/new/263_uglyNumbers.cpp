/*
263. Ugly Number My Submissions Question
Total Accepted: 41335 Total Submissions: 115882 Difficulty: Easy
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/

/*
keep divide by 2 and 3 an 5, if result is 1 return true, otherwise return false;
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;    


class Solution {
public:
    bool isUgly(int num) {
        if(num<=0) return 0;
        int no = maxDivide(num, 2);
        no = maxDivide(no, 3);
        no = maxDivide(no, 5);
       
        return (no == 1)? 1 : 0;
    }
    
    /*This function divides a by greatest divisible 
  power of b*/
    int maxDivide(int a, int b)
    {
      while (a%b == 0)
       a = a/b; 
      return a;
    }   
};

int main(){

    return 0;
}