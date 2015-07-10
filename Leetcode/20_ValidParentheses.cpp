/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
use one stack:
if (, [, {  push into stack
else if ) ] }:
check if it matchs stack top

after travese string if stack is empty
return ture

*/


class Solution {
private:
	stack<char> st;
public:
    bool isValid(string s) {
        if(s.empty()) return false;

        for(char i:s){
        	if(i=='('||i=='{'||i=='['){
        		st.push(i);
        	}else if(i==')'||i=='}'||i==']'){
        		if(!st.empty()){
	        		if(st.top()=='('&& i==')')
	        			st.pop();
	        		else if(st.top()=='['&& i==']')
	        			st.pop();
	        		else if(st.top()=='{'&& i=='}')
	        			st.pop();
	        		else
	        			return false;
        		}else{
        			return false;
        		}
        	}else{
        		return false; //inculded illegal char
        	}
        }

        if(st.empty())
        	return true;
        else
        	return false;
    }
};

int main(){
	Solution s;
	cout<<s.isValid("((()))")<<endl;
	cout<<s.isValid("[[}}")<<endl;
	cout<<s.isValid("(((")<<endl;

	return 0;
}