/*

Determine whether an integer is a palindrome. 
Do this without extra space.

*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


//this way is use string as extra space, 848ms
class Solution_old {
public:
    bool isPalindrome(int x) {
    	if(x<0)  //minus number cannot idenity as palindrome
    		return false;
    	string str=to_string(x); //c++11
    	int strlength=str.size();
    	int i=0;
    	int j=strlength-1;
    	while(i<j){
    		if(str[i]!=str[j]){
    			return false;
    		}
    		
    		i++;
    		j--;
    	}

    	return true;
    }
};



/* 
use code in reverse integer  running time:76ms!
*/

class Solution {
public:
     bool isPalindrome(int x) {
        if(x<0)  //minus number cannot idenity as palindrome
            return false;
        
        int rx=reverse(x);
        
        return rx==x;
    }

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
	cout<<s.isPalindrome(5125)<<endl;



	return 0;
}
