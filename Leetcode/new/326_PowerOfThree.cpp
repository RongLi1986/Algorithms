/*
326. Power of Three 
Total Accepted: 2159 Total Submissions: 5961 Difficulty: Easy
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this questio
*/


/*
if a number is power of 3, it could be divided by 1162261467 since 1162261467 is largest
number (intger) of power of 3.
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        //corner case
        if(n<=0) return false;
    
        if(1162261467%n==0)
            return true;
        return false;
    }
};

int main(){

    return 0;
}