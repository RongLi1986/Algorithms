/*
Given a target number and an integer array sorted in ascending order. Find the total number of occurrences of target in the array.
*/

#include <iostream>
using namespace std;

/*
binary search twice and return index's difference
*/

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
     
    int binarySearchLast(vector<int> &array, int target) {
        // write your code here
        if(array.empty()) return -1;
        if(array[array.size()-1]==target) return array.size()-1;
        
        int left = 0;
        int right = array.size()-1;
        
        while(left+1<right){
            int mid=(left+right)/2;
            if(array[mid]<=target){
                left=mid;
            }else{
                right=mid;
            }
        }
        
        if(target==array[left]){
            return left;
        }
        
        return -1;
    }
    
    
    int binarySearchFirst(vector<int> &array, int target) {
        // write your code here
        if(array.empty()) return -1;
        if(array[0]==target) return 0;
        
        int left = 0;
        int right = array.size()-1;
        
        while(left+1<right){
            int mid=(left+right)/2;
            if(array[mid]<target){
                left=mid;
            }else{
                right=mid;
            }
        }
        
        if(target==array[right]){
            return right;
        }
        
        return -1;
    }
    
    int totalOccurrence(vector<int>& A, int target) {
        // Write your code here
        int left = binarySearchFirst(A, target);
        int right = binarySearchLast(A, target);
        
        if(left == -1){ 
            return 0;
        }else{
            return right - left + 1;
        }
    }
};

int main(){

	return 0;
}