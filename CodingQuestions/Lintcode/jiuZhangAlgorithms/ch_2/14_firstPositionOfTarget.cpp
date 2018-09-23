/*
First Position of Target

For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.
*/

#include <iostream>
using namespace std;

/*
binary search
O(lgn)
 */
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.empty()) return -1;
        
        int left = 0;
        int right = array.size()-1;
        
        while(left+1<right){
            int mid=(left+right)/2;
            if(array[mid]<target){
                left=mid;
            }else {
                right=mid;
            }
        }
        
        if(target==array[right]){
            return right;
        }else if (target==array[left]){
            return left;
        }
        
        return -1;
    }
};


int main(){

	return 0;
}