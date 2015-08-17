/*
Search in Rotated Sorted Array II
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

/*
linear way is same.
for binary search way: 
first it needs to find where is rot, left or right
add avoid duplicates.
for worse case, it will be O(n);
*/

#include <iostream>
using namespace std;

class Solution {
public:
	//this could pass tested cases, but can we do better?
    bool search_old(int A[], int n, int target) {
        for(int i=0;i<n;i++){
            if(target==A[i])
                return true;
        }        
        return false;
    }

    bool search(int A[], int n, int target) {
    	int left=0;
    	int right=n-1;
    	int mid;
    	while(left<=right){
    		mid=(left+right)/2;
    		if(A[mid]==target) return true;
    		if(A[mid]>A[left]){ //rot in right
    			if(A[left]<=target && target<A[mid])
    				right=mid-1;
    			else
    				left=mid+1;
    		}else if(A[mid]<A[left]){ //rot in left
    			if(A[right]>=target && target>A[mid])
    				left=mid+1;
    			else
    				right=mid-1;
    		}else //mid ==left but is not target
                left++; //dup case O(n) to kill;
    	}

    	return false;
    }
};

int main(){
	Solution s;
	int A[]={1,3,1,1,1};
	int size=5;
	cout<<s.search(A,size,3)<<endl;

	return 0;
}