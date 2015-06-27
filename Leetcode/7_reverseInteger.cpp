/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
#include <iostream>
using namespace std;


/*
output times ten
output + mod of x
x divide by 10
*/

class Solution {
public:
    int reverse(int x) {
        int output=0;
        while(x!=0){
            output*=10;
            output+=x%10;
            x=x/10;
        }
        
        return output;
    }
};

int main(){
	Solution s;
	cout<<s.reverse(123)<<endl;

	return 0;
}