/*
Single Number 
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
solution:
scan vector, XOR each number, result is single number
tip:same number XOR is 0,0 XOR any number is any number
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> A) {
        int i=0;
        int out=0;
        while(i<A.size()){
            out^=A[i];
            i++;
        }

        return out;
    }
};

int main(){
	Solution s;
	int A[]={2,1,2,10,10};
	cout<<s.singleNumber(A,5)<<endl;

}