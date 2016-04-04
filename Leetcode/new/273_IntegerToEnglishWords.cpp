/*
273. Integer to English Words 
Convert a non-negative integer to its english words representation. 
Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

/*
recursive
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string numberToWords(int num){
        string res;
        res = numberToWordsHelper(num,res);
        return res.substr(1,res.size()-1);;
    }
    
    string numberToWordsHelper(int num, string tmp) {
        //cout<<num<<" "<<tmp<<endl;
        if(num/1000000000){
            tmp=numberToWordsHelper(num/1000000000, tmp);
            tmp+=" Billion";
            num=num%1000000000;
            if(num==0) return tmp;
            return numberToWordsHelper(num, tmp);
        }else if(num/1000000){
            tmp=numberToWordsHelper(num/1000000, tmp);
            tmp+=" Million";
            num=num%1000000;
            if(num==0) return tmp;
            return numberToWordsHelper(num, tmp);
        }else if(num/1000){
            tmp=numberToWordsHelper(num/1000, tmp);
            tmp+=" Thousand";
            num=num%1000;
            if(num==0) return tmp;
            return numberToWordsHelper(num, tmp);
        }else if(num/100){
            tmp+=outOne(num/100);
            tmp+=" Hundred";
            num=num%100;
            if(num==0) return tmp;
            return numberToWordsHelper(num, tmp);
        }else if(num/10){
            if(num/10>1){
                tmp+=outTen(num/10);
                num=num%10;
                if(num==0) return tmp;
                return numberToWordsHelper(num, tmp);
            }else{ //11 to 19
                tmp+=outTwenty(num);
                return tmp;
            }
        }else{
            tmp+=outOne(num);
            //tmp+=" ";
            return tmp;
        }
    }
    
    string outTwenty(int num){
        if(num==19)
            return " Nineteen";
        if(num==18)
            return " Eighteen";
        if(num==17)
            return " Seventeen";
        if(num==16)
            return " Sixteen";
        if(num==15)
            return " Fifteen";
        if(num==14)
            return " Fourteen";
        if(num==13)
            return " Thirteen";
        if(num==12)
            return " Twelve";
        if(num==11)
            return " Eleven";
        if(num==10)
            return " Ten";
    }
    
    string outOne(int num){
        if(num==9)
            return " Nine";
        if(num==8)
            return " Eight";
        if(num==7)
            return " Seven";
        if(num==6)
            return " Six";
        if(num==5)
            return " Five";
        if(num==4)
            return " Four";
        if(num==3)
            return " Three";
        if(num==2)
            return " Two";
        if(num==1)
            return " One";
        if(num==0)
            return " Zero";
    }
    
    
    string outTen(int num){
        if(num==9)
            return " Ninety";
        if(num==8)
            return " Eighty";
        if(num==7)
            return " Seventy";
        if(num==6)
            return " Sixty";
        if(num==5)
            return " Fifty";
        if(num==4)
            return " Forty";
        if(num==3)
            return " Thirty";
        if(num==2)
            return " Twenty";
        if(num==1)
            return " Ten";
    }  
};

int main(){

    return 0;
}