/*
Search in Rotated Sorted ArrayII

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

/*
linear search
because if left right mid has same value, it cannot know who (left and right) should be changed
*/

#include <iostream>
using namespace std;
class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        //it must be O(n)
        if(A.empty()) return false;
        
        for(int i=0;i<A.size();i++){
            if(A[i]==target)
                return true;
        }
        
        return false;
    }
};

int main(){

	return 0;
}