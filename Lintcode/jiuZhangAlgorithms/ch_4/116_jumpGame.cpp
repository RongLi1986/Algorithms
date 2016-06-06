/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 Notice

This problem have two method which is Greedy and Dynamic Programming.

The time complexity of Greedy method is O(n).

The time complexity of Dynamic Programming method is O(n^2).

Example
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include <iostream>
using namespace std;

/*
DP
for f(0) it is 1 (1) 
and for f(x) = if(A[X] could be reached);
*/

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        if(A.empty())
            return false;
        vector<int> jump(A.size() , 0);
        jump[0] = 1;
        
        for(int i=0; i<A.size(); i++){
            if(jump[i] == 0){
                return false;
            }else{
                
                for(int j=i; j<i+A[i]+1; j++){
                    if(j==A.size()-1)
                        return true;
                    jump[j] = 1;
                }
                
            }
        }
        
        return false;
    }
};


int main(){

	return 0;
}