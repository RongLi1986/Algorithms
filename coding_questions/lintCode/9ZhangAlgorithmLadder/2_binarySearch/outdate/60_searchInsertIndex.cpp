/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume NO duplicates in the array.
*/

#include <iostream>
using namespace std;

/*
binary search, consider some corner case
O(lgn)
 */

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &array, int target) {
        if(array.empty()) return 0;
        // write your code here
        int left=0;
        int right=array.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(array[mid]==target){
                //find it return
                return mid;
            }else if(array[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        
        if(right<0){ //one item in array
            return left;
        }else if(array[right]>target) 
            return right;
        else
            return left;
    }
};

//from JiuZhang
class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // find first position >= target
        if (A.size() == 0) {
            return 0;
        }
        
        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = (end - start) / 2 + start;
            if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (A[start] >= target) {
            return start;
        }
        if (A[end] >= target) {
            return end;
        }
        
        return A.size();
    }
};

int main(){
    //test
    /*
    [], 1
    [10] ,9
    [1,2,4,5] 3
     */

	return 0;
}