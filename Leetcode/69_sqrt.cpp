/*
Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.
*/

/*
find a number tmp which make tmp=x/tmp
it could use binary search
up=x,down=0
tmp=(up+down)/2
if(up-down<=1) return tmp;
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int sqrt(int x) {

        if(x==0 || x==1) return x;
     
        int up =x;
        int down =0;

        int temp=(up+down)/2;
        //cout<<temp<<endl;
        while(up-down>1){
        	if(temp>x/temp){
        		up=temp;
        		temp=(up+down)/2;
        	}else{
        		down=temp;
        		temp=(up+down)/2;
        	}
        }
        //cout<<up<<" "<<down<<endl;
        return temp;
    }
};


int main(){

	Solution s;
	
	cout<<s.sqrt(2)<<endl;
	cout<<s.sqrt(3)<<endl;
	cout<<s.sqrt(9)<<endl;
	cout<<s.sqrt(1)<<endl;
	cout<<s.sqrt(64)<<endl;
	cout<<s.sqrt(3)<<endl;
	cout<<s.sqrt(4)<<endl;
	cout<<s.sqrt(0)<<endl;
	cout<<s.sqrt(1600)<<endl;
	cout<<s.sqrt(8)<<endl;
	
	cout<<s.sqrt(2147483647)<<endl;
	
	return 0;
}