/*
Search Insert Position
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

/*
finished by linear search
and binary search
*/


#include <iostream>
using namespace std;

class Solution {
public:
    //O(n)
    int searchInsert(int A[], int n, int target) {
        if(A==NULL) return 0;
        int insertIndex=0;

        for(int i=0;i<n;i++){
        	if(A[i]==target){
        		return i;
        	}else if(A[i]>target){
        		insertIndex=i;
        		return insertIndex;
        	}
        }

        return n;
    }

    //O(logn)  binary search
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;

        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) 
                return mid;
            else if(nums[mid]>target){
                if(mid==0) return 0;
                if(target>nums[mid-1])
                    return mid;
                right=mid-1;
            }else{
                if(mid==nums.size()-1)
                    return nums.size();
                if(target<nums[mid+1])
                    return mid+1;
                left=mid+1;
            }
        }
    }
};


int main(){
	int A[]={1,3,5,6};
	Solution s;
	cout<<s.searchInsert(A,4,5)<<endl;
	cout<<s.searchInsert(A,4,2)<<endl;
	cout<<s.searchInsert(A,4,7)<<endl;
	cout<<s.searchInsert(A,4,0)<<endl;

	return 0;
}