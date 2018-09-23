/*
Search for a Range 
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

/*
solutionI: O(n) linear search, check corner cases
solutionII: O(lgn) binary search, 
find a double in vector
then if it could be target, return index.
or return -1, -1
*/ 


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out; 
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target&&flag==0){
                out.push_back(i);
                flag=1;
            }
            if(nums[i]!=target&&flag==1){
                out.push_back(i-1);
                return out;
            }
        }
        if(out.size()==1){ //last item is still target
            out.push_back(nums.size()-1);
        }
        
        if(out.empty()){
            out.push_back(-1);
            out.push_back(-1);
        }
        
        return out;
    }	

    vector<int> searchRange(int A[], int n, int target) {
        int left=binarySearch(A, n, target-0.5);
    	int right=binarySearch(A, n, target+0.5);
    	if(A[right]!=target)
    		right--;
    	if(A[left]!=target)
    		left++;
    	
    	vector<int> out;
    	
    	if(nums[left]==nums[right]&&nums[right]==target){
    		out.push_back(left);
    		out.push_back(right);
    	}else{
    		out.push_back(-1);
    		out.push_back(-1);
    	}
    	
        return out;
    }	

    int binarySearch(int A[], int length, double target){
		int left=0;
		int right=length-1;
		int mid=0;

		while(left<=right){
			mid=(left+right)/2;
			cout<<mid<<endl;
			if(target>A[mid]){
				left=mid+1;
			}else if(target<A[mid]){
				right=mid-1;
			}else if(target==A[mid])
				return mid;
		}

		return mid;
    }
};


int main(){
	int A[]={5, 7, 7, 8, 8, 10};
	int B[]={1,2,3};
	Solution s;
	//vector<int> v=s.searchRange(A,6,6);
	//cout<<v[0]<<" "<<v[1]<<endl;
	cout<<s.binarySearch(B,3,1.5)<<endl;
	//vector<int> v1=s.searchRange(B,3,2);
	//cout<<v1[0]<<" "<<v1[1]<<endl;
	return 0;
}
