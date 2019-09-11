/*
Description

Given an array of integers, how many three numbers can be found in the array, 
so that we can build an triangle whose three edges length is the three numbers that we find?

Example
Example 1:

Input: [3, 4, 6, 7]
Output: 3
Explanation:
They are (3, 4, 6), 
         (3, 6, 7),
         (4, 6, 7)
Example 2:

Input: [4, 4, 4, 4]
Output: 4
Explanation:
Any three numbers can form a triangle. 
So the answer is C(3, 4) = 4
*/

#include <iostream>
#include <vector>
#include <map>
//#include <algorithm>

using namespace std;

/*
sort array and use two pointers to find the answer
*/ 

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        sort(S.begin(), S.end());
        int ans = 0;
        
        for(int i = 0; i < S.size(); i++){
            int left = 0;
            int right = i - 1;
            while(left < right){
                if(S[left] + S[right] > S[i]){
                    ans = ans + (right - left);
                    right--;
                }else{
                    left++;
                }
            }
        }
        
        return ans;
    }
};