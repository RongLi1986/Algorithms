/*
264. Ugly Number II My Submissions Question
Total Accepted: 22691 Total Submissions: 86096 Difficulty: Medium
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> result;
        int start1=0; //X2
        int start2=0; //X3
        int start3=0; //x5
        result.push_back(1);
        while(result.size()<n){
            int val1=result[start1]*2;
            int val2=result[start2]*3;
            int val3=result[start3]*5;
            
            int uglyNum=min(val1,min(val2,val3));
            
            result.push_back(uglyNum);
            
            if(val1==uglyNum)
                start1++;
            
            if(val2==uglyNum)
                start2++;
            
            if(val3==uglyNum)
                start3++;
        }
        
        return result[n-1];
    }
};

int main(){
    classRoom c;
    classRoom::boy b;
    b.lookEye();
    b.touchBreast(c);
    //girl g(1,0);
    //boy b;
    //b.touchBreast(g);
    //b.lookEye(g);
    return 0;
}