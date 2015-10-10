/*
Excel Sheet Column Number Total Accepted: 1649 Total Submissions: 3885 My Submissions Question Solution 
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

/*
scan string from right to left, for each char
equation is:
    result=char's number*26^(s.size()-(i+1))
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int out=0;
        int j=0;
        for(int i=s.size()-1;i>=0;i--){
            out+=toNum(s[i])*pow(26,j);
            j++;
        }
        
        return out;
    }
    
    int num(char s){
        return s-'A'+1;;
    }
};

int main(){
    Solution s;
    cout<<s.titleToNumber("AZ")<<endl;
    
	return 0;
} 