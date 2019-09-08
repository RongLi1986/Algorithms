/*
Climbing Stairs II

A child is running up a staircase with n steps, and can hop either 1 step, 
2 steps, or 3 steps at a time. Implement a method to count how many possible 
ways the child can run up the stairs.

Example
n=3
1+1+1=2+1=1+2=3=3

return 4
*/

#include <iostream>
using namespace std;

/*
*/

class Solution {
private:
    unordered_map<int, int> hashMap;
public:
    /**
     * @param n an integer
     * @return an integer
     */
    int climbStairs2(int n) {
        // Write your code here
        if(n==0)
            return 1;
        
        return climbStairs2Helper(n);
    }
    
    int climbStairs2Helper(int n){
        if(hashMap.find(n)!=hashMap.end())
            return hashMap[n];
        
        if(n < 0){
            return 0;
        }
            
        if(n==0){
            hashMap[n] = 1;
            return 1;
        }
        
        int res =  climbStairs2Helper(n-3) + climbStairs2Helper(n-2) + climbStairs2Helper(n-1);
        hashMap[n]=res;
        
        return res;
    }
};
