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
sol1: use num_stk and op_stk, scan input string. 
handle each item by different cases.

and need to take care many corner case

sol2: but this way is TLE in this question!!
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

class Solution_TLE {
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