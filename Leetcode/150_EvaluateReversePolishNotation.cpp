/*
Evaluate Reverse Polish Notation 
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
Show Tags
*/

/*
use stack trace result.
scan the sting vector. for each string:
I is only number, just push it in stack
II is operator, pop two number and do caculation,
then push result in stack.
III if has operator and number, split them and push number part (maybe negative number)
into stack

it need to consider illege case
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
private:
    stack<int> stk;
public:
    int evalRPN(vector<string>& token) {
        int res=0;
        std::locale loc;
        for(int i=0;i<token.size();i++){
            if(isdigit(token[i][0],loc)){
                //cout<<"kk"<<endl;
                int number;
                stringstream(token[i]) >> number;
                stk.push(number);
            }else if(token[i].size()==1){
                //cout<<"oo"<<endl;
                if(token[i]=="+"){
                    int number2=stk.top();
                    stk.pop();
                    int number1=stk.top();
                    stk.pop();
                    stk.push(number1+number2);
                }else if(token[i]=="-"){
                    int number2=stk.top();
                    stk.pop();
                    int number1=stk.top();
                    stk.pop();
                    stk.push(number1-number2);
                }else if(token[i]=="*"){
                    int number2=stk.top();
                    stk.pop();
                    int number1=stk.top();
                    stk.pop();
                    stk.push(number1*number2);
                }else if(token[i]=="/"){
                    int number2=stk.top();
                    stk.pop();
                    int number1=stk.top();
                    stk.pop();
                    stk.push(number1/number2);
                }else
                    return -1;
            }else{ //negative number
                if(token[i][0]=='+'){
                    int number;
                    stringstream(token[i].substr(1,token[i].size()-1)) >> number;
                    stk.push(number);
                }else if(token[i][0]=='-'){
                    int number;
                    stringstream(token[i].substr(1,token[i].size()-1)) >> number;
                    stk.push(-1*number);
                }else{
                    return -1;
                }
            }
        }
        
        if(!stk.empty())
            res=stk.top();
            
        return res;
    }
};



class Solution2 {
private:
    stack<string> s;    
public:
    int evalRPN(vector<string> &tokens) {
        int size=tokens.size();
        if (size==1) return stoi(tokens[0]);
        int i=0;
        string result;
        while(i<size){
            if(isOperators(tokens[i])){
                //cout<<"push stack"<<endl;
                string n1=s.top();
                s.pop();
                string n2=s.top();
                s.pop();
                result=doOperation(n2,n1,tokens[i]);
                s.push(result);

            }else if(isInteger(tokens[i])){
                //cout<<"push stack"<<endl;
                s.push(tokens[i]);

            }else{
                cerr<<"illegal op!!"<<endl;
            }
            i++;
        }
        
        return stoi(result);
    }

    bool isOperators(string s){
        int size=s.size();
        if(size==1){
            if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/')
                return true;
            return false;
        }else
            return false;
    }

    bool isInteger(string s){
        int size=s.size();
        int i=1;
        
        if(s[0]-'0'>9||s[0]-'0'<0){
            if((!s[0]=='-'||s[0]=='+')){
                return false;
            }else{
                if(size==1)
                    return false;
            }
        }
        
        while(i<size){
            if(s[i]-'0'>9||s[i]-'0'<0)
                return false;
            i++;
        }

        return true;
    }

    string doOperation(string n1, string n2, string n3){
        int A=stoi(n1);
        int B=stoi(n2);
        int result;
        if(n3[0]=='+'){
            result=A+B;
        }else if(n3[0]=='-'){
            result=A-B;
        }else if(n3[0]=='*'){
            result=A*B;
        }else{
            result=A/B;
        } 
        string s=to_string(result);
        return s;
    }
};

int main(){
    Solution s;
    /*
    cout<<s.isInteger("3")<<endl;
    cout<<s.isInteger("-4")<<endl;
    cout<<s.isOperators("+")<<endl;
    cout<<s.doOperation("3","-4","+")<<endl;
    */
    vector<string> v={"0","3","/"};
    cout<<s.evalRPN(v)<<endl;

    return 0;
}