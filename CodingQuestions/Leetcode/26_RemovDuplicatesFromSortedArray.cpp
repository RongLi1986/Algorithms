/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

*/

//normally, we need to shift array, but it will cost O(n^2)..
//so we compare the one and last non-repeat one..
//
//vector:
//compare i and j , delete repeat one
#include <iostream>
using namespace std;

class Solution {
public:
    /*
    int removeDuplicates(int A[], int n) {
        if(A==NULL) return 0;
        if(n==0) return 0;

        int i=0;
        int j=1;
        int newLength=1;
        while(j<n){
        	if(A[i]!=A[j]){
        		i++;
        		A[i]=A[j];
        		j++;
        		newLength+=1;
        	}else{
        		j++;
        	}

        }

        return newLength;
    }
    */
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i=0;
        int j=1;
        int newLength=1;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
                j++;
                newLength+=1;
            }else{
                j++;
            }

        }

        return newLength;
    }

    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i=0;
        int j=1;
        int newLength=1;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                i++;
                j++;
            }else{
                nums.erase(nums.begin()+j);
            }

        }

        return nums.size();
    }

};

int main(){
	Solution s;
	int A[]={1,2,2,3,4,5,5,6,8,9,9,11};
	int newLength=s.removeDuplicates(A,12);
	cout<<newLength<<endl;
	for(int i=0;i<newLength;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}