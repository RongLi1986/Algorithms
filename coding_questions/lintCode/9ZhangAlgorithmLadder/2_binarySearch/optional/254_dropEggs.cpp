/*
Drop Eggs

 Description
 Notes
 Testcase
 Judge
There is a building of n floors. If an egg drops from the k th floor or above, it will break. If it's dropped from any floor below, it will not break.

You're given two eggs, Find k while minimize the number of drops for the worst case. Return the number of drops in the worst case.

Have you met this question in a real interview? Yes
Clarification
For n = 10, a naive way to find k is drop egg from 1st floor, 2nd floor ... kth floor. But in this worst case (k = 10), you have to drop 10 times.

Notice that you have two eggs, so you can drop at 4th, 7th & 9th floor, in the worst case (for example, k = 9) you have to drop 4 times.

Example
Given n = 10, return 4.
Given n = 100, return 14.
*/

#include <iostream>
using namespace std;

/*
TODO: dp solution
*/
class Solution {
public:
    /**
     * @param n an integer
     * @return an integer
     */
    int dropEggs(int n) {
        // Write your code here
        long floor = n;
        if(n==0 || n==1)
            return n;
            
        
        for(long i=0;i<INT_MAX;i++){
            if((i*i+i)/2>=floor)
                return (int)i;
        }
        
    }
};