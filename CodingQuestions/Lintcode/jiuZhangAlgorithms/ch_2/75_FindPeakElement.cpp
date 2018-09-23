/*
There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peek if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.
*/

/*
binary search find

left and right index need to move to high value direction
*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int left = 0;
        int right = A.size()-1;
        
        while(left <= right){
            int mid = (left + right)/2;
            
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1]){ //this is peak
                return mid;
            }else if(A[mid] > A[mid-1] && A[mid] < A[mid+1]){  // mid is higher so move left
                left = mid+1;
            }else if(A[mid] < A[mid-1] && A[mid] > A[mid+1]){   //mid is lower so change right
                right = mid-1;
            }else{ //mid is bottom move any one is OK
                right = mid -1;
            }
        }
        
        return -1;
    }
};


int main(){

	return 0;
}