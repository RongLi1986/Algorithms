/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*/

#include <iostream>
using namespace std;

/*
greedy
if i could reach end, return count
else find farthest point from i;
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    
    //DP cannot pass large Data set
    /* 
    int jump(vector<int> A) {
        // wirte your code here
        if(A.empty())
            return -1;
        
        //jumpMap record minimum jumping times to this index.
        vector<int> jumpMap(A.size(), -1);
        jumpMap[0] = 0;
        
        for(int i = 0; i<A.size(); i++){
            int val = jumpMap[i];
            if(i+A[i]>=A.size()-1)
                return val+1;
            if(val >= 0){
                for(int j = i + 1; j< i+A[i]+1; j++){
                    if(j<A.size()){
                        if(jumpMap[j] != -1)
                            jumpMap[j] = min(val +1, jumpMap[j]);       
                        else
                            jumpMap[j] = val + 1;
                    }
                }        
            }else{
                return -1; //cannot reach
            }
        }
        
        return jumpMap[A.size()-1];
    }
    */
    
    //Greedy O(n)
    int jump(vector<int> A) {
        // wirte your code here
        int n=A.size();
        
        int i=0;
        int cnt=0;
        while(i<n){
            if(A[i]+i >= A.size()-1)
                return cnt+1;
            else{
                int j=i+1;
                int max = INT_MIN;
                int maxIndex = 0;
                while(j<A[i]+i+1){
                    if(j+A[j]>max){
                        max=j+A[j];
                        maxIndex=j;
                    }
                    
                    j++;
                }
                //cout<<maxIndex<<endl;
                i=maxIndex;
                cnt++;
            }
        }
    
        return cnt;
    }
};

int main(){

	return 0;
}