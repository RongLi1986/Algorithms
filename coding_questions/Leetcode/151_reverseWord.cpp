//Reverse Words in a String 
/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

/*
since testcase has "   " multi-space case. so I have to
use stack to reorder words and rebuild input string.
or it need kill repeated space before.

this solution is base on stack way
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        stack<string> stk;
        string sTemp;
        int nLength=s.size();
        
        //put words into stack
        for(int i=0;i<nLength;i++){
            if(s[i]!=' '){
                sTemp+=s[i];
            }else{
                if(!sTemp.empty()){
                    stk.push(sTemp);
                    sTemp.clear();
                }
            }
        }
        //put last word into stack
        if(s[nLength-1]!=' ')
            stk.push(sTemp);

        //clear input string
        s.clear();

        //build string from stack
        while(!stk.empty()){
            s+=stk.top();
            s+=' ';
            stk.pop();
        }
        
        //kill last space
        if(!s.empty())
            s.pop_back();
    }
};

int main(){
	string s1("a is b");
	cout<<s1<<endl;
	Solution s;
	s.reverseWords(s1);
	cout<<s1<<endl;

	return 0;

}