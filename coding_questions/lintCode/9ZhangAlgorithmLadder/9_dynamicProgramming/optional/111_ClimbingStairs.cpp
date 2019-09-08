/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example
Given an example n=3 , 1+1+1=2+1=1+2=3

return 3
*/

#include <iostream>
using namespace std;

/*
DP
for f(0) it is 1 (1) and f(1) is 2 
and for f(x, y) = f(x-1) + f(x -2);
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
     //DP
    int climbStairs(int n)
    {
        if(n<=1) return 1;
        vector<int> stairs(n,0);
        
        stairs[0] = 1;
        stairs[1] = 2;
        
        for(int i = 2; i< n; i++ ){
            stairs[i] =stairs[i-1] + stairs[i-2];
        }
        
        return stairs[n-1];
    }

};


int main(){

	return 0;
}