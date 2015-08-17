/*
Remove Duplicates from Sorted Array II 

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

/*
basic way is:
use two index i and j, 
if array[i]==array[j] j++;
if array[i]!=array[j] update new length, swap i+1 and j,j++

for duplicates case, it needs a flag to know it is first duplicates or
second one.
*/ 


#include <iostream>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i=0;
        int j=1;
        int newLength=1;
        int flag=0; //first or second
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
                j++;
                newLength+=1;
                flag=0;
            }else if(nums[i]==nums[j]&&flag==0){
            	i++;
                nums[i]=nums[j];
                j++;
                newLength+=1;
                flag=1;
            }else{
                j++;
            }
        }

        return newLength;
    }



    int removeDuplicates_old(int A[], int n) {
		if(A==NULL) return 0;
		if(n<3) return n;
		
		int i=0;
		int j=1;
		int k=2;
		int newLength=2;
		while(k<n){
			if(A[i]==A[j]&&A[j]==A[k]){
				k++;
			}else{
				j++;
				swap(A,j,k);
				k++;
				i++;
				newLength++;
			}
		}

		return newLength;
    }

    void swap(int A[], int j, int k){
    	int temp=A[j];
    	A[j]=A[k];
    	A[k]=temp;
    }
};

int main(){
	int A[]={1,1,1,2,2,3};
	Solution s;
	int newL=s.removeDuplicates(A,6);
	cout<<newL<<endl;

	for(int i=0;i<newL;i++){
		cout<<A[i]<<"-";
	}
	cout<<endl;

}