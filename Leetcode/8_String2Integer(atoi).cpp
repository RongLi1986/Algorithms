/*
String to Integer (atoi) Total Accepted: 53310 Total Submissions: 410790 My Submissions Question Solution 
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

/*
just follow requirements of atoi:
The function first discards as many whitespace characters as necessary until the first 
non-whitespace character is found. Then, starting from this character, takes an optional 
initial plus or minus sign followed by as many numerical digits as possible, and interprets 
them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is 
out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is 
returned.
*/

//need to change signature, and it didn't hold output (64bits) overflow case
class Solution_old {
public:
    int atoi(const char *str) {
        
        //str==NULL
        if (str==NULL)
            return 0;

        int strLen=strlen(str);
        
        //remove whitespace
        int n=0;
        const char* pch=str;

        while(*pch==' '&& n<strLen){
            n++;
            pch++;
        }

        strLen=strLen-n;

        //all whitspace case
        if(strLen<=0)
            return 0;

        long long output=0;  //finial ouput why long is not 64bits in here??
        int i=0;       //pch's index
        
        bool minus=0;   //minus 

        //signed handle
        if(pch[0]<48||pch[0]>57){  //not number
            if(!(pch[0]=='+'||pch[0]=='-')) //is signed
                return 0;
            else{
                if(pch[0]=='-'){
                    minus=1;
                    i++; 
                }else if(pch[0]=='+'){
                    minus=0;
                    i++; 
                }
            }
        }

        while(i<strLen){
            
            if(pch[i]>'9'||pch[i]<'0')
                break;
                
            output*=10;
            switch (pch[i]){
                case '0':
                    output+=0;
                    break;
                case '1':
                    output+=1;
                    break;
                case '2':
                    output+=2;
                    break;
                case '3':
                    output+=3;
                    break;
                case '4':
                    output+=4;
                    break;
                case '5':
                    output+=5;
                    break;
                case '6':
                    output+=6;
                    break;
                case '7':
                    output+=7;
                    break;
                case '8':
                    output+=8;
                    break;
                case '9':
                    output+=9;
                    break;
            }
            i++;
        }
        
        if(minus==1)
            output*=-1;

        //cout<<sizeof(output)<<endl;  //we need long long
        //overflow and underflow check
        if(output>2147483647)
            return 2147483647;

        if(output<-2147483648)
            return -2147483648;


        return static_cast<int>(output);
    }
};


class Solution {
private:
    bool m_minus;
public:
    int myAtoi(string str) {
        int strLen=str.size();
        m_minus=0;
        
        //make string legal
        string s=adjustStr(str,strLen);
        
        int sLen=s.size();

        //if s is empty
        if(sLen==0) return 0;  
        
        if(s.size()>10){ //this will make sure output should not overflow
            if(m_minus==0)
                return INT_MAX;
            else
                return INT_MIN;

        }

        long long output=0;  //it is 64bits, finally it output 32bits
        int i=0;       //index

        while(i<sLen){
            if(s[i]-'0'>=0&&s[i]-'0'<=9){
                output*=10;    //times 10
                switch (s[i]){
                    case '0':
                        output+=0;
                        break;
                    case '1':
                        output+=1;
                        break;
                    case '2':
                        output+=2;
                        break;
                    case '3':
                        output+=3;
                        break;
                    case '4':
                        output+=4;
                        break;
                    case '5':
                        output+=5;
                        break;
                    case '6':
                        output+=6;
                        break;
                    case '7':
                        output+=7;
                        break;
                    case '8':
                        output+=8;
                        break;
                    case '9':
                        output+=9;
                        break;
                }
            }else{ //illegal case
                return 0;
            }

            i++;
        }

        //check minus
        if(m_minus==1)
            output*=-1;

        //overflow and underflow check
        if(output>2147483647)
            return INT_MAX;

        if(output<-2147483648)
            return INT_MIN;

        return static_cast<int> (output);

    }

    string adjustStr(string str, int strLen){
        string s;
        bool op=0;  //op=1 means, it forbidden sign op 
        bool space=0;  //if space =1 means it forbidden space
        
        int n=0;
        while(n<strLen){
            //cout<<str[n]<<endl;
            if(str[n]!=' '){
                if(str[n]-'0'>=0 && str[n]-'0'<=9){
                    op=1;  //no + or - for now
                    space=1; //no space for now
                    s+=str[n];
                }else {
                    if(str[n]=='+'||str[n]=='-'){
                        if(op==1)      
                            break;
                        else{
                            op=1;
                            //s+=str[n];
                            if(str[n]=='-')
                                m_minus=1;  //keep sign bit
                            space=1;  //no space for now
                        }
                    }else{
                        break;  
                    }
                }  
            }else{  //' '
                if(space==1)
                    break;
            }
            n++;
        }
        //cout<<"s is *"<<s<<"*"<<endl;

        return s;
    }
};


int main(){
    Solution s;
    cout<<s.myAtoi("9223372036854775809")<<endl;

}