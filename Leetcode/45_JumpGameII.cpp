/*
Jump Game II  
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

/*
我们维护两个变量，当前能达到的最远点p以及下一次能达到的最远点q，在p的范围内迭代计算q，然后更
新步数，并将最大的q设置为p。重复这个过程知道p达到终点。

temp 当前最远点
maxx 下一次最远点 
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //this is non-negative array, so it could be reach end
    //Greedy  same algorithm??
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxx=0;
        int temp=0;
        int num=0;
        int i=0;
        while(i<n)
        {
            if(temp>=n-1) break;
            while(i<=temp)
            {
                maxx=max(maxx,i+nums[i]);
                ++i;
            }
            num++;
            temp=maxx;            
        }
        return num;
        
    }
};


class Solution_old {
public:
	//TLE worst case O(n^2)
    int jump_TLE(int A[], int n) {
        vector<int> B(n,0);
        int count=0;
        return findJumpIndex_TLE(A, n, B, count);
    }

    int findJumpIndex_TLE(int A[], int n, vector<int> &B, int count){
    	if(n<=1)  return count;
    	int target=n-1;
    	for(int i=n-2;i>=0;i--){
    		int dis=n-1-i;
    		B[i]=A[i]-dis;
    		if(B[i]>=0)
    			target=i;

    	}

    	int next=target+1;;
    	//cout<<i<<endl;
    	count++;


    	return findJumpIndex_TLE(A, next, B, count);
    }	


    int jump(int A[], int n) {
        int start=0;
        int dis=A[0]+start;
        if(n==1) return 0; //[0] case

        int count=1;
        int maxValue=-1;
        int maxIndex=-1;
        while(dis<n-1){
        	maxValue=-1;
        	maxIndex=-1;
        	for(int i=start+1;i<=dis;i++){
        		if(A[i]+i>=maxValue){
        			maxValue=A[i]+i;
        			maxIndex=i;
        		}
        	}

        	start=maxIndex;
        	//cout<<dis<<endl;
        	dis=maxValue;
        	count++;
        }

        return count;
        
    }
};

int main(){
	Solution s;
	//int A[]={2,3,1,1,4};
	int A[]={1,1,1,1,1};
	cout<<s.jump(A,5)<<endl;

	return 0;
}


