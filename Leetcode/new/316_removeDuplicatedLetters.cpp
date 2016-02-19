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
use stack.

first scan count number of each unique letter in string (use map)

then scan string again. for each letter, if it is not in stack, compare it with stack top's letter.

if top letter cnt is not 0 and larget than it, pop stack and push it.
 
用栈。

首先对字符串出现的个数进行统计。

然后对字符串扫描，每遇到一个字符串，判断其是否在栈中，如果在则跳过。（计数 – 1）

如果不在栈中，和栈顶的元素判断，要是当前栈顶的元素比较大而且cnt不为0（也就是说之后还有这个元素），就把栈顶弹出。然后把当前的元素入栈。
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
    	unordered_map<char,int> visitMap; //letter in stk
    	stack<char> stk;
    	//count letter's numbers
    	for(int i=0;i<s.size();i++){
    		if(hashMap.find(s[i])==hashMap.end()){
    			hashMap[s[i]]=1;
    		}else{
    			hashMap[s[i]]++;
    		}
    		visitMap[s[i]]=0;
    	}

    	for(int i=0;i<s.size();i++){
    		if(visitMap[s[i]]==0){
    			if(stk.empty()){
    				stk.push(s[i]);
    				visitMap[s[i]]=1;
    			}else{
    				while(stk.top()>s[i] && hashMap[stk.top()]>0 ){
    					visitMap[stk.top()]=0;
    					stk.pop();
    					if(stk.empty()) break;
    				}
    				
    				stk.push(s[i]);
    				visitMap[s[i]]=1;
    				
    			}
    		}
    		
    		hashMap[s[i]]--;
    	}

    	string res;

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