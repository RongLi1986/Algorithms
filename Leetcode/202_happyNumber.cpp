/*
Happy Number
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

/*
solution:
follow the instruction, for input n, caculate sum of each number(n%10)'s power

if sum is 1, return true;
if not change n to sum, loop it again

it need a set to record sum number which is not equal to 1. so for sum can be
found in set. return false;
*/


#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int result=0;
        set<int> record;
        while(result!=1){
            while(n!=0){
                int a=n%10;
                result+=a*a;
                n=n/10;                
            }
            if(result!=1){
                if(result==0||record.find(result)!=record.end())
                    return false;
                record.insert(result);
                n=result;
                result=0;
            }
        }

        return true;
    }
};


int main(){
	int n=0;

	Solution s;
    
	cout<<s.isHappy(n)<<endl;

	return 0;
}