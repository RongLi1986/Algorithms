/*
Plus One 

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

*/

/*
just like add binary, but this time we handle caculation
in vector. if carry is 1 at end, we need to create a new vector
O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()) return digits;
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]=digits[i]+carry;
            if(digits[i]>=10){
                digits[i]%=10;
                carry=1;
            }else{
                carry=0;
            }
        }
        
        if(carry==1){
            vector<int> out(digits.size()+1,1);
            for(int i=1;i<digits.size()+1;i++){
                out[i]=digits[i-1];
            }
            return out;
        }else
            return digits;
    }
};

//why we cannot access in reverse  way
class Solution_old {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(),digits.end());

        vector<int>::iterator itr=digits.begin();
        int carry=0;
        (*itr)+=1;
        if(*itr==10){
            *itr=0;
            carry=1;
        }else{
            carry=0;
        }
        itr++;

        for(;itr!=digits.end();itr++){
            (*itr)+=carry;
            if(*itr==10){
                *itr=0;
                carry=1;
            }else
                carry=0;
        }

        if(carry==1)
            digits.push_back(1);

        reverse(digits.begin(),digits.end());

        return digits;
    }
};



int main(){
	vector<int> v={8,6,5,4,2,3,1,9}; //c++11
	Solution s;
	vector<int> v1=s.plusOne(v);
	vector<int>::iterator itr=v1.begin();
	for(;itr!=v1.end();itr++){
		cout<<*itr<<"-";
	}
	cout<<endl;



	return 0;
}