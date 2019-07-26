/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/


/*
two diff situation, 
1. like case 27==>AA, 27/26=1 and 27%26==1
2. like case 52==>AZ, 52%26==0 so last char should be 'Z', 
and first 'A' is get by (52-1)/26==1

does it exist more directly way?
see math function
*/



#include <iostream>
#include <string>
using namespace std;

//recursive
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        if(n<=26 && n>=1) {
            char temp=n-1+'A';
            //cout<<temp<<endl;
            res.append(1,temp);
            return res;
        }

        if(n%26==0){ //for case 52 78
            res+=convertToTitle((n-1)/26);
            res+="Z";
        }else{  //normal case
            res+=convertToTitle(n/26);
            res+=convertToTitle(n%26);    
        }
        
        return res;
    }
};

//math function
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while( n )
        {
            result.insert( result.begin(), ( n - 1 ) % 26 + 'A' );
            n = ( n - 1 ) / 26;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.convertToTitle(52)<<endl;
    
	return 0;
} 