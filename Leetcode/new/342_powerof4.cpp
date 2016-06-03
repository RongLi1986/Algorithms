/*
342. Power of Four   My Submissions QuestionEditorial Solution
Total Accepted: 6665 Total Submissions: 19878 Difficulty: Easy
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

/*
sol:
1.makesure it is power of 2
2.use 0x55555555 to mark it
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) 
            return false;
         
        int t=(num & (num-1));
        if(t!=0){
            return false;
        }

        if((num | 0x55555555) == 0x55555555)
            return true;
        
        return false;
    }
};

int main(){

    return 0;
}