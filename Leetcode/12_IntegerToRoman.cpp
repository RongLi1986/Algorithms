/*
Integer to Roman Total Accepted: 21320 Total Submissions: 62430 My Submissions Question Solution 
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

/*
1.recursive way:
2.iterative way:

they are similar, it need compare 1000, 900, 500, 400, 100, 90, 50,
40, 10, 9, 5, 4, 1. and match Roman as M, CM, D, CD, C, XC, L, XL,
X,IX,V,IV, and I. 
*/


#include <iostream>
#include <string>
//iterative code
class Solution {
public:
    string intToRoman(int num) {
    	string out;
    	if(num==0) return out;

    	while(num>=1000){
    		out+="M";
    		num=num-1000;
    	}

        while(num>=900){
            out+="CM";
            num=num-900;
        }

        while(num>=500){
            out+="D";
            num=num-500;
        }

        while(num>=400){
            out+="CD";
            num=num-400;
        }

        while(num>=100){
            out+="C";
            num=num-100;
        }

        while(num>=90){
            out+="XC";
            num=num-90;
        }

        while(num>=50){
            out+="L";
            num=num-50;
        }

        while(num>=40){
            out+="XL";
            num=num-40;
        }
        
        while(num>=10){
            out+="X";
            num=num-10;
        }

        while(num>=9){
            out+="IX";
            num=num-9;
        }

        while(num>=5){
            out+="V";
            num=num-5;
        }

        while(num>=4){
            out+="IV";
            num=num-4;
        }

        while(num>=1){
            out+="I";
            num=num-1;
        }        

        return out;
    }
};



//recursive code
public class Solution1 {
    public String intToRoman(int num) {
        if(num>=1000) return "M"+intToRoman(num-1000);
        if(num>=900) return "CM"+intToRoman(num-900);
        if(num>=500) return "D"+intToRoman(num-500);
        if(num>=400) return "CD"+intToRoman(num-400);
        if(num>=100) return "C"+intToRoman(num-100);
        if(num>=90) return "XC"+intToRoman(num-90);
        if(num>=50) return "L"+intToRoman(num-50);
        if(num>=40) return "XL"+intToRoman(num-40);
        if(num>=10) return "X"+intToRoman(num-10);
        if(num>=9) return "IX"+intToRoman(num-9);
        if(num>=5) return "V"+intToRoman(num-5);
        if(num>=4) return "IV"+intToRoman(num-4);
        if(num>=1) return "I"+intToRoman(num-1);
        return "";
    }
};


int main(){

    return 0;
}
