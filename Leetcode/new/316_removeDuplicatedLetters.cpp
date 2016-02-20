/*
316. Remove Duplicate Letters My Submissions Question
Total Accepted: 8288 Total Submissions: 34995 Difficulty: Medium
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/


/*
using stack.

first scan string and count times of each letter in string (use map)

then scan string again. for each letter, if it is not in stack, begin a loop which compare it with stack top's letter.

if top letter count is not 0 (which means it will appear) and larger than current letter, pop stack top letter.

when loop overand push it.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
    	unordered_map<char,int> hashMap;
    	unordered_map<char,int> visitMap; //letter in or not in stk
    	stack<char> stk;
    	
        //count letter's appear times
    	for(int i=0;i<s.size();i++){
    		if(hashMap.find(s[i])==hashMap.end()){
    			hashMap[s[i]]=1;
    		}else{
    			hashMap[s[i]]++;
    		}
    		visitMap[s[i]]=0;  //initial not in stk
    	}

        //
    	for(int i=0;i<s.size();i++){
    		if(visitMap[s[i]]==0){
    			if(stk.empty()){ //first one
    				stk.push(s[i]);
    				visitMap[s[i]]=1;
    			}else{
    				while(stk.top()>s[i] && hashMap[stk.top()]>0 ){
    					visitMap[stk.top()]=0;
    					stk.pop();
    					if(stk.empty()) break;  //corner case stk become empty
    				}
    				
    				stk.push(s[i]);
    				visitMap[s[i]]=1;
    				
    			}
    		}
    		
    		hashMap[s[i]]--;
    	}

    	string res;

        //res is reverse stk;
    	while(!stk.empty()){
    		res=stk.top()+res;
    		stk.pop();
    	}

    	return res;
    }
};

int main(){
    string input="cbacdcbc";

    Solution s;

    cout<<s.removeDuplicateLetters(input)<<endl;

    return 0;
}