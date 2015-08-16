/*
Sort Colors 
Given an array with n objects colored red, white or blue, sort them so that objects of the
same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
#include <iostream>
#include <algorithm>
using namespace std;

/*
use counting sort, since they are only three different numbers in this array
*/

class Solution {
public:
    //libaray sort...forbiden to use
    void sortColors_lib (vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }

    //counting sort
    void sortColors(vector<int>& nums) {
    	int n=nums.size();
        int i=0;
    	int countOne=0;
    	int countZero=0;

    	while(i<n){
    		if(nums[i]==0){
    			countZero++;
    		}else if(nums[i]==1){
    			countOne++;
    		}
    		i++;
    	}

    	i=0;
    	while(i<n){
    		if(countZero!=0){
    			nums[i]=0;
    			countZero--;
    		}else if(countOne!=0){
    			nums[i]=1;
    			countOne--;
    		}else{
    			nums[i]=2;
    		}
    		i++;
    	}
    }
};

int main(){

	vector<int> A={0,2,1,0,2,1,1,0,1}; //0 0 0 1 1 1 1 2 2
	Solution s;
	//s.sortColors(A,9);
	s.sortColors2(A);

	int i=0;
	while(i<9){
		cout<<A[i]<<" ";
		i++;
	}
	cout<<endl;
	
	return 0;
}