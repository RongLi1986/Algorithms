/*
Rotate Array  
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

//how to do it in space O(1)

/*
solution:
create mem  B, and caculte k, then O(n) copy item from A to B
then copy mem B back to A;
*/

#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n=nums.size();
        if(n>0){
        	k=k%n;  //for k>n

	        vector<int> tmp(n,0);

	        for(int i=n-k;i<n;i++){
	        	tmp[i-(n-k)]=nums[i];
	        }

	        /*
	        cout<<"tmp:";
	        for(int i=0;i<n;i++){
				cout<<tmp[i]<<",";
			}
			cout<<endl;
			*/
			/*
			cout<<"nums:";
	        for(int i=0; i<n;i++){
				cout<<nums[i]<<",";
			}
			cout<<endl;
			*/

	        for(int i=0;i<n-k;i++){
	        	tmp[i+k]=nums[i];
	        }

	        /*
	        cout<<"tmp:";
	        for(int i=0;i<n;i++){
				cout<<tmp[i]<<",";
			}
			cout<<endl;
			*/

	        //memcpy(nums, tmp, n*4);
	        for(int i=0;i<n;i++)
                nums[i]=tmp[i];


	        /*
	        cout<<"nums:";
	        for(int i=0; i<n;i++){
				cout<<nums[i]<<",";
			}
			cout<<endl;
			*/
    	}

    }
};

int main(){
	int nums[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54};
	int nums2[]={1,2};
	int nums3[]={1,2,3,4,5,6,7};

	Solution s;
	s.rotate(nums2,2,1);

	for(int i=0;i<2;i++){
		cout<<nums2[i]<<",";
	}
	cout<<endl;

	return 0;
}