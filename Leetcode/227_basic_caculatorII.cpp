/*
Basic Calculator II
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

/**
this question we need NPN:
算法：
一、 将中缀表达式转换成后缀表达式算法：
1、从左至右扫描一中缀表达式。
2、若读取的是操作数，则判断该操作数的类型，并将该操作数存入操作数堆栈
3、若读取的是运算符
  (1) 该运算符为左括号"("，则直接存入运算符堆栈。
  (2) 该运算符为右括号")"，则输出运算符堆栈中的运算符到操作数堆栈，直到遇到左括号为止。
  (3) 该运算符为非括号运算符：
      (a) 若运算符堆栈栈顶的运算符为括号，则直接存入运算符堆栈。
      (b) 若比运算符堆栈栈顶的运算符优先级高或相等，则直接存入运算符堆栈。
      (c) 若比运算符堆栈栈顶的运算符优先级低，则输出栈顶运算符到操作数堆栈，并将当前运算符压入运算符堆栈。
4、当表达式读取完成后运算符堆栈中尚有运算符时，则依序取出运算符到操作数堆栈，直到运算符堆栈为空。
 
二、逆波兰表达式求值算法：
对后缀表达式求值比直接对中缀表达式求值简单。在后缀表达式中，不需要括号，而且操作符的优先级也不再起作用了。
您可以用如下算法对后缀表达式求值：
    初始化一个空堆栈
    从左到右读入后缀表达式
    如果字符是一个操作数，把它压入堆栈。
    如果字符是个操作符，弹出两个操作数，执行恰当操作，然后把结果压入堆栈。
    如果您不能够弹出两个操作数，后缀表达式的语法就不正确。
    到后缀表达式末尾，从堆栈中弹出结果。若后缀表达式格式正确，那么堆栈应该为空。

*/
class Solution {
private:
  vector<string> stk_num;
  stack<string> stk_op;
  //stack<string> stk_cal; //it need reverse stk_op

public:
    int calculate(string s) {
        
        generateNPN(s);
        
        for(int i=0;i<stk_num.size();i++)
            cout<<stk_num[i]<<endl;
        
        //cout<<stk_num.size()<<endl;
        for(int i=0;i<stk_num.size();i++){
            if(isNumber(stk_num[i])){
                stk_op.push(stk_num[i]);
            }else{
                string tmp2=stk_op.top();
                stk_op.pop();
                string tmp1=stk_op.top();
                stk_op.pop();

                string result=calculateOp(tmp1, tmp2, stk_num[i]);
                stk_op.push(result);
            }
        }
        

        string out=stk_op.top();
        int value = atoi(out.c_str());
        return value;
    }

    bool isNumber(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'>=0 && s[i]-'0'<=9){

            }else
                return false;
        }

        return true;
    }

    void generateNPN(string &s){
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){

            }
            else if(s[i]-'0'>=0 && s[i]-'0'<=9){
                string tmp2;
                tmp2+=s[i];
                i++;
                while((s[i]-'0'>=0 && s[i]-'0'<=9)&&i<s.size()){
                    tmp2+=s[i];
                    i++;
                }
                i--;
                stk_num.push_back(tmp2);
            }else if(s[i]=='('){
                stk_op.push("(");
            }else if(s[i]==')'){
                while(stk_op.top()!="("){
                    string tmp=stk_op.top();
                    stk_num.push_back(tmp);
                    stk_op.pop();
                }
                if(stk_op.top()=="(")
                    stk_op.pop();
            }else{
                string tmp2;
                tmp2+=s[i];
                while(!stk_op.empty()){
                    if(stk_op.top()=="(")
                        break;
                    if(LowSameLevel(tmp2,stk_op.top())){
                        string tmp=stk_op.top();
                        stk_num.push_back(tmp);
                        stk_op.pop();    
                    }else{
                        break;
                    }
                }

                stk_op.push(tmp2);
            }
            i++;
        }

        while(!stk_op.empty()){
            string tmp=stk_op.top();
            stk_num.push_back(tmp);
            stk_op.pop();    
        }
    }

    bool LowSameLevel(string s1, string s2){
        
        if(s1=="*"||s1=="/"){
            if(s2=="*"||s2=="/"){
                return true;
            }else if(s2=="+"||s2=="-"){
                return false;
            }    
        }else if(s1=="+"||s1=="-"){
            if(s2=="*"||s2=="/"){
                return true;
            }else if(s1=="+"||s2=="-"){
                return true;
            }
        }
        return false;
    }

    string calculateOp(string num1, string num2, string op){
        int i1,i2,result;
        if(op=="+"){
            i1=atoi(num1.c_str());
            i2=atoi(num2.c_str());
            result=i1+i2;  
            //cout<<"kk"<<result<<endl;
        }else if(op=="-"){
            i1=atoi(num1.c_str());
            i2=atoi(num2.c_str());;
            result=i1-i2;
            cout<<"kk"<<result<<endl;
        }else if(op=="*"){
            i1=atoi(num1.c_str());
            i2=atoi(num2.c_str());;
            result=i1*i2;
            //cout<<"kk"<<result<<endl;
        }else if(op=="/"){
            i1=atoi(num1.c_str());
            i2=atoi(num2.c_str());;
            result=i1/i2;
            //cout<<"kk"<<result<<endl;
        }

        string out;
        ostringstream convert;
        convert<<result;
        out=convert.str();
        return out;
    }
};

int main(void)
{   
    string s=" 1 - 2 /30";
    Solution ss;
    cout<<ss.calculate(s)<<endl;

    return 0;
}