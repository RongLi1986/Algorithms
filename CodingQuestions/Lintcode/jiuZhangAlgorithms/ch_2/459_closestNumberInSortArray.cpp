/*
Given a target number and an integer array A sorted in ascending order, find the index i in A such that A[i] is closest to the given target.

Return -1 if there is no element in the array.
*/

#include <iostream>
using namespace std;

/*
binary search find mid and comapre mid -1, mid and mid +1 with target
*/

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int closestNumber(vector<int>& A, int target) {
        // Write your code here
        if(A.empty()) return -1;
        int left =0;
        int right =A.size()-1;
        int mid=0;
        
       
        
        while(left<=right){
            mid=(left+right)/2;
            
            if(A[mid]==target){
                return mid;
            }else if(A[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        
        int min = INT_MAX;
        int min_Index;
        if(abs(target-A[mid])<min){
            min=abs(target-A[mid]);
            min_Index = mid;
        }
        
        if(mid==0){
            if(abs(target-A[mid+1])<min){
                min = abs(target-A[mid+1]);
                min_Index = mid+1;
            }
        }else if(mid==A.size()-1){
            if(abs(target-A[mid-1])<min){
                min = abs(target-A[min-1]);
                min_Index = mid-1;
            }
        }else{
            if(abs(target-A[mid+1])<min){
                min = abs(target-A[mid+1]);
                min_Index = mid+1;
            }
            
            if(abs(target-A[mid-1])<min){
                min = abs(target-A[mid-1]);
                min_Index = mid-1;
            }
        }
        
        return min_Index;
    }
};


int main(){

	return 0;
}