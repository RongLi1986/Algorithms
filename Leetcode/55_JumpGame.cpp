/*
Jump Game 
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

/*
first, let us start from last item in vector,
then move index to left. to find most left one which
could reach to this target. loop to do it until target
equal to 0. but if target don't change, return false;
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        int target=nums.size()-1;
        int last_target;
        int tmp_target;
        while(target>0){
            last_target=target;
            tmp_target=target;
            for(int i=target-1;i>=0;i--){
                if(tmp_target-i<=nums[i])
                    tmp_target=i;
            }
            target=tmp_target;
            if(last_target==target)
                return false;
        }
        return true;
    }
};


int main(){
	Solution s;
	//int A[]={2,3,1,1,4};
	int A[]={1,1,1,1,1};
	cout<<s.jump(A,5)<<endl;

	return 0;
}


