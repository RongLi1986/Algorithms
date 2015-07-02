/*
Regular Expression Matching Total Accepted: 42045 Total Submissions: 203193 My Submissions Question Solution 
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/



/*
递归实现。

思路：

isMatch(s, p):

1. 当前p为0时，若s也是0时，则返回true，否则为false

2. 当前p不为0时，

　　1) p的下一个不是'*'时

　　　　if: 当前s与p匹配，

　　　　　　则表明到此都是匹配的，只需要检查isMatch(s + 1, p + 1)

　　　　else:

　　　　　　返回false

　　2) p的下一个是'*'时，

　　　　while: 当前s与p匹配，即表明至此也是匹配的

　　　　　　if: 当前s与下一个p也都匹配，即isMatch(s, p + 2)，则返回true

　　　　　　else: s++

　　　　此时，当前s与当前p已经不匹配了（之前s都是匹配的），则检测下一个模板isMatch(s, p + 2)
*/

#include <iostream>
#include <string>

using namespace std;


//pass string reference
class Solution {
public:
    bool isMatch(string s,string p){
        return isMatchRecursive(s,p,0,0);
    }

    bool isMatchRecursive(string& s, string& p, int s_index, int p_index) {
        int sLength=s.size();
        int pLength=p.size();

        if(p_index>pLength-1){
            if(s_index>sLength-1)
                return true;
            else
                return false;
        }

        if(p[p_index+1]!='*'){
            if(p[p_index]==s[s_index] || (p[p_index]=='.' && s_index<=sLength-1)){
                return isMatchRecursive(s,p, s_index+1, p_index+1);
            }else
                return false;
        }else{
            while(p[p_index]==s[s_index] || (p[p_index]=='.' && s_index<=sLength-1)){
                if (isMatchRecursive(s, p, s_index, p_index+2)) 
                    return true;
                s_index++;
            }
        }
        
        return isMatchRecursive(s, p, s_index, p_index+2);
    }
};


int main(){
	Solution s;
    cout<<s.isMatch("aa","a")<<endl;
    cout<<s.isMatch("aa","aa")<<endl;
    cout<<s.isMatch("aaa","aa")<<endl;
    cout<<s.isMatch("aa", "a*")<<endl;
    cout<<s.isMatch("aa", ".*")<<endl;
    cout<<s.isMatch("ab", ".*")<<endl;
    cout<<s.isMatch("aab", "c*a*b")<<endl;

	return 0;
}








