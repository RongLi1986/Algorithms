/*
Search in Rotated Sorted Array 
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

/*
solution I: O(n) linear search
solution II: BinarySearch
first need to know where is rotation index, 
is between left and mid or mid and right?
then decide move left or right 
*/



#include <iostream>
using namespace std;

class Solution {
public:
	//this wau could pass tested cases, but we need to use binary search
    int search_old(int A[], int n, int target) {
        for(int i=0;i<n;i++){
            if(target==A[i])
                return i;
        }        
        return -1;
    }

    //binary search
    int search(int A[], int n, int target) {
    	int left=0;
    	int right=n-1;
    	int mid;
    	while(left<=right){
    		mid=(left+right)/2;
    		if(A[mid]==target) return mid;
    		if(A[mid]>=A[left]){ //rot in right
    			if(A[left]<=target && target<A[mid])
    				right=mid-1;
    			else
    				left=mid+1;
    		}else{
    			if(A[right]>=target && target>A[mid])
    				left=mid+1;
    			else
    				right=mid-1;
    		}
    	}

    	return -1;
    }
};

int main(){
	Solution s;
	int A[]={4,5,6,7,0,1,2};
	int size=7;
	cout<<s.search(A,size,3)<<endl;

	return 0;
}