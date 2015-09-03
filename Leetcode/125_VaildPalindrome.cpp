/*
Valid Palindrome T

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/



#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        string t=stringFilter(s);
        
        int start=0;
        int end=t.size()-1;
        
        while(start<end){
           //cout<<s[start]<<" "<<end<<endl;
            if(t[start]!=t[end]){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
        
    }
    
    string stringFilter(string& s){
        int nLength=s.size();
        int i=0;
        string sc;
        for(;i<nLength;i++){
            if(isalpha(s[i])||isdigit(s[i])){
                s[i] = toupper(s[i]);
                sc.push_back(s[i]);
            }
        }
        
        return sc;
    }
};

int main(){
	Solution s;
	cout<<s.isPalindrome("abccba")<<endl;  //1
	cout<<s.isPalindrome("ab,cc ba")<<endl; //1
	cout<<s.isPalindrome("ab,c a")<<endl;  //0
	cout<<s.isPalindrome("")<<endl; 		//1
	cout<<s.isPalindrome(",,..!!")<<endl;  //0

	return 0;
}