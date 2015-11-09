/*
Basic Calculator Total Accepted: 425 Total Submissions: 2488 My Submissions Question Solution 
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

/*
use num_stk and op_stk, scan input string. 
handle each item by different cases.

and need to take care many corner case
*/
class Solution {
stack<string> num_stk;
stack<string> op_stk;
public:
    int calculate(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]=='(') //"(" push it into stk
                num_stk.push("(");
            else if(s[i]-'0'<=9 && s[i]-'0'>=0){ //number: pop other number and get their result
                                  //conner case: "(", op_stk is empty
                                  
                //figure out number
                string tmp2;
                while(i<s.size()&&(s[i]-'0'<=9 && s[i]-'0'>=0)){
                    tmp2+=s[i];
                    i++;
                }
                i--;//go back one step                  
                //cout<<tmp2<<endl;
                
                if(op_stk.empty()) //first number
                    num_stk.push(tmp2);
                else if(num_stk.top()=="(")
                    num_stk.push(tmp2);
                else{
                    string tmp1=num_stk.top();
                    num_stk.pop();
                    string op=op_stk.top();
                    op_stk.pop();
                    string res=doCaculation(tmp1,tmp2,op);
                    num_stk.push(res);
                }
            }else if(s[i]==')'){ //")" pop two numbers from stk and caculate result
                                 //corner case: (1)  only one number
                if(num_stk.top()=="("){
                    num_stk.pop();   
                    continue;
                }else{
                    if(!op_stk.empty()){  //ther are two numbers
                        string tmp2=num_stk.top();
                        num_stk.pop();
                        num_stk.pop();//kill'('
                        string tmp1=num_stk.top();
                        num_stk.pop();
                        string op=op_stk.top();
                        op_stk.pop();
                        string res=doCaculation(tmp1,tmp2,op);
                        num_stk.push(res);
                    }else{ //(1)
                        string tmp=num_stk.top();
                        num_stk.pop();
                        num_stk.pop();//kill'('
                        num_stk.push(tmp);
                    }
                }
            }else if(s[i]=='+'||s[i]=='-'){ //operator, just push it into op_stk
                if(s[i]=='+')
                    op_stk.push("+");
                else
                    op_stk.push("-");
            }else{
                //" "  do nothing
            }
            i++;
        }
        
        //finally output int from num_stk.top()
        int value = atoi(num_stk.top().c_str());
        return value;
    }
    
    string doCaculation(string s1,string s2,string op){
        int num1 = atoi(s1.c_str());
        int num2 = atoi(s2.c_str());
        int res=0;
        
        if(op=="+"){
            res=num1+num2;
        }else if(op=="-"){
            res=num1-num2;
        }else //exceptions
            return to_string(INT_MAX);
        
        return to_string(res);
    }
    
};
int main(void)
{   
    string s="11";
    Solution ss;
    cout<<ss.calculate(s)<<endl;

    return 0;
}