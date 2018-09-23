/*
Power of Two 
Given an integer, write a function to determine if it is a power of two.
*/

/*
if a number is power of two, it can only have one 1 in its binary form
how to find  times of 1 in number's binary from?
n&(n-1)
*/


#include <iostream>
using namespace std;


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        return !(n&n-1);
    }
};


class Solution_old {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        int tmp=2;
        int i=1;
        while(n>=tmp){
            if(n==tmp) {
                return true;
            }
            i++;
            tmp=pow(2,i);
            
            //cout<<tmp<<endl;
            //check overflow
            if(tmp<=0) return false;
        }
        
        return false;
    }
};


int main(){

	return 0;
}