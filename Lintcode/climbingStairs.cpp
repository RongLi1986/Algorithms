/*
Climbing Stairs

39% Accepted
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Have you met this question in a real interview? Yes
Example
Given an example n=3 , 1+1+1=2+1=1+2=3

return 3
*/

/*
recursive and DP
recursive will TLE

DP:
set a array for keeping how many ways to this stair.
eq is array[1]=1;
      array[2]=2; //1+1 or 2;
      array[3]=array[2]+array[1];

      so,
        array[n]=array[n-1]+array[n-2];

caculate and return array[n]; 
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs_Recursive(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }

     //DP
    int climbStairs(int n)
    {
        vector<int> res(n,0);
        res[0] = 1;
        res[1] = 2;
        for (int i = 2; i < n; i++)
        {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n-1];
    }

};


int main(){

	return 0;
}