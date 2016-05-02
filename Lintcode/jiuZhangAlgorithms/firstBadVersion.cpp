/*
The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, 
so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is the first bad one. 
The details interface can be found in the code's annotation part.
*/

/*
binary search
*/

#include <iostream>
using namespace std;
/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        
        int left=1;
        int right=n;
        
        while(left<=right){
            int mid=(left+right)/2;
            if(SVNRepo::isBadVersion(mid)==true){
                right=mid-1;
            }
            else
                left=mid+1;
        }
        
        if(left<=n)
            return left;
        return right;
        
    }
};

int main(){

	return 0;
}