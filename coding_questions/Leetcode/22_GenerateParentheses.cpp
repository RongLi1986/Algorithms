/*
Generate Parentheses 
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

/*
use recrusive 
*/

class Solution {
private:
	vector<string> out;
public:
     vector<string> generateParenthesis(int n) {
    	string s;
    	getParenthesis_new(n,n,s);

    	return out;
    }

    void getParenthesis(int left, int right, string s){
    	//cout<<s<<"left is "<<left<<"right is "<<right<<endl;
    	if(left<0||right<left) return;  //illegal case

    	if(left==0 && right==0){
    		out.push_back(s);
    	}else{
	    	if(left>0){
	    		string l=s;
	    		l+="(";
	    		int left_next=left-1;
	    		
	    		getParenthesis(left_next,right,l);
	    	}

	    	if(right>left){
	    		string r=s;
	    		r+=")";
				int right_next=right-1;
				
				getParenthesis(left,right_next,r);
	    	}
    	}
    }

};

int main(){
	Solution s;
	vector<string> tmp=s.generateParenthesis_new(3);
	int size=tmp.size();
	for(int i=0;i<size;i++)
		cout<<tmp[i]<<endl;

	return 0;
}