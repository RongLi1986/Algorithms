/*Climbing Stairs
You are climbing a stair case. 
It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?
*/

/*
DP way:
if n is 1, res is 1. 
if n is 2, res is 2 (2 or 1+1)

if n is 3, res is 3 (1+1+1 or 2+1 or 2+1)

eq is array[n]=array[n-1]+array[n-2]

return array[n-1];
*/



#include <iostream>
using namespace std;

//recursive way
class Solution {
public:
    int climbStairs_recursive(int n) {  //
        
        if(n<=2) return n;

        return climbStairs_recursive(n-1)+climbStairs_recursive(n-2);
    }

     int climbStairs(int n) {  //fast a liite bit for passing test
     	if(n==0) return 1;
     	if(n<=2) return n;

     	return climbStairs(n-3)+2*climbStairs(n-2);
     }
};


//DP way
class SolutionDP {
public:
    int climbStairs(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> path(n,0);
        path[0]=1;
        path[1]=2;
        for(int i=2;i<n;i++){
            path[i]=path[i-1]+path[i-2];
        }
        
        return path[n-1];
    }
};


int main(){
	Solution s;
	cout<<s.climbStairs(1)<<endl;  //1
	cout<<s.climbStairs(2)<<endl;  //2
	cout<<s.climbStairs(3)<<endl;  //3
	cout<<s.climbStairs(4)<<endl;  //5
	cout<<s.climbStairs(5)<<endl;  //8
	cout<<s.climbStairs(44)<<endl;  //
	return 0;
}