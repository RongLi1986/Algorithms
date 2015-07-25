/*
Roman to Integer Total Accepted: 21129 Total Submissions: 62149 My Submissions Question Solution 
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

/*
Roman numerals, as used today, are based on seven symbols:[1]

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1,000


Symbols are placed from left to right in order of value, starting with the largest. However, in a few specific cases,[2] to avoid four characters being repeated in succession (such as IIII or XXXX) these can be reduced using subtractive notation as follows:[3][4]

the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX) respectively
X can be placed before L and C to make 40 (XL) and 90 (XC) respectively
C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern[5]

solution:
for each char, we convert to int, but for I and X and C we need to check them with next char
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int sumOut=0;
    	int i=0;
    	int size=s.size();
    	while(i<size){
    		int temp=transroman(s[i]);
    		if((temp==1||temp==10||temp==100)&&i!=size-1){
    			int next=transroman(s[i+1]);
    			if(temp<next){
    				temp=next-temp;
    				i++;
    			}
    		}
    		sumOut+=temp;
    		i++;
    	}

    	return sumOut;
    }

    int transroman(char s){
    	int out=0;
    	if(s=='I') {
		  	out=1;
		}else if(s=='V'){  
		  	out=5;
		}else if(s=='X'){  
		  	out=10;
		}else if(s=='L'){  
		  	out=50;
		}else if(s=='C'){  
		  	out=100;
		}else if(s=='D'){  
		  	out=500;
		}else if(s=='M'){  
		  	out=1000;
		}else{
			cout << "error"<<endl;
			out=-1;
		}

		return out;
	}
};


int main(){
	Solution s;
	//int out=s.transroman('M');
	//cout<<out<<endl;
	cout<<s.romanToInt("IIX")<<endl;


}