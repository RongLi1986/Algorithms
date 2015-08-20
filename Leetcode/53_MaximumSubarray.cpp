/*
Maximum Subarray 
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

/*
def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

DP:
traverse array,set localMaxValue and globalMax Value
compare localmaxValue and maxValue+localValue, get max one;
use a global value to keep max Sum;

*/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int maxEnd=nums[0];
        int maxSofar=nums[0];
        for(int i=1;i<nums.size();i++){
            maxEnd=max(nums[i],maxEnd+nums[i]);
            maxSofar=max(maxSofar,maxEnd);
        }
        
        return maxSofar;
    }
};


class Solution_old {
public:
	//O(n^2)
    int maxSubArray_old(int A[], int n) {
        if(n==1) return A[0];
        int sum=0;
        int max=INT_MIN;
        int i=0;
        int start=0;
        while(start<n){
        	i=start;
        	sum=0;
	        while(i<n){
	        	sum+=A[i];
	        	if(sum>max)
	        		max=sum;
	        	if(sum<0){
	        		break;
	        	}
	        	i++;
	        }
	        start++;
    	}
        
    	return max;
    }

    //o(n)
    int maxSubArray(int A[], int n) {
        if(n==1) return A[0];
        int sum=0;
        int max=INT_MIN;
        
        int start=0;
        while(start<n){
        	if(sum<0){
	        	sum=A[start];
	        }else{
	        	sum+=A[start];
	        }

	        if(sum>max)
	        	max=sum;

	        start++;
    	}
        
    	return max;
    }

};

int main(){
	int A[]={-2,1,-3,4,-1,2,1,-5,-4};
	
	Solution s;
	cout<<s.maxSubArray(A,9)<<endl;

	return 0;
}