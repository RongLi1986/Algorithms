/*
Simplify Path Total Accepted: 20121 Total Submissions: 101219 My Submissions Question Solution 
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/


/*
solution: using a stack, cut input string by "/"
handle each part of string. 
at last, generate output by stack.

need to conisder many corner cases
*/ 


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	vector<string> stack;
public:
    string simplifyPath(string path) {
		//first find "/"
		int found=path.find("/");
		
		while(found!=string::npos){
			int start=found+1;
			found=path.find("/",found+1);
			//cout<<"start:"<<start<<"found:"<<found<<endl;
			
			//cut string
			string str = path.substr (start,found-start);
			
			//handle str with stack
			//cout<<str<<endl;
			if(!str.compare("..")){
				//stack pop
				if(!stack.empty()){
					stack.pop_back();
				}
			}else if(!str.compare(".")||str.empty()){
				//do nothing
			}else{
				//push stack
				stack.push_back(str);
			}
			
		}

		//generate output
		int size=stack.size();
		string out="";

		for(int i=0;i<size;i++){
			//cout<<stack[i]<<" ";
			out+="/";
			out+=stack[i];
		}

		//for "/" corner case
		if(out.empty())
			out+="/";  

    	return out;
    }
};



int main(){
	Solution s;
	string str="/...";
	cout<<s.simplifyPath(str)<<endl;

	return 0;
}