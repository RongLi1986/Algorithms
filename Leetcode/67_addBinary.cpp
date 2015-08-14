/**
Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
binary add with carry
*/

#include <iostream> 
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

 using namespace std;
 


//faster
class Solution {
public:
    string addBinary(string a, string b) {
        string s(max(a.size(),b.size()),42);
        int c=0;
        int a_index=a.size()-1;
        int b_index=b.size()-1;
        
        for(int i=s.size()-1;i>=0;i--){
            if(a_index>=0&&b_index>=0){
                if(c==0){
                    if(a[a_index]=='0'){
                        if(b[b_index]=='0'){
                            c=0;
                            s[i]='0';
                        }else{  //b_index=='1'
                            c=0;
                            s[i]='1';
                        }
                    }else{ //a[a_index]=='1'
                        if(b[b_index]=='0'){
                            c=0;
                            s[i]='1';
                        }else{
                            c=1;
                            s[i]='0';
                        }
                    }
                }else{ //c==1
                    if(a[a_index]=='0'){
                        if(b[b_index]=='0'){
                            c=0;
                            s[i]='1';
                        }else{  
                            c=1;
                            s[i]='0';
                        }
                    }else{ //a[a_index]=='1'
                        if(b[b_index]=='0'){
                            c=1;
                            s[i]='0';
                        }else{
                            c=1;
                            s[i]='1';
                        }
                    }
                }
            }else if(a_index>=0){
                if(c==0){
                    if(a[a_index]=='0'){
                            c=0;
                            s[i]='0';
                    }else{
                        c=0;
                        s[i]='1';
                    }
                }else{
                    if(a[a_index]=='0'){
                        c=0;
                        s[i]='1';
                    }else{
                        c=1;
                        s[i]='0';
                    }
                }
            }else{
                if(c==0){
                    if(b[b_index]=='0'){
                            c=0;
                            s[i]='0';
                    }else{
                        c=0;
                        s[i]='1';
                    }
                }else{
                    if(b[b_index]=='0'){
                        c=0;
                        s[i]='1';
                    }else{
                        c=1;
                        s[i]='0';
                    }
                }
            } 
            
            a_index--;
            b_index--;
        }
        
        if(c==1)
            return "1"+s;
        else
            return s;
        
    }
};

class Solution_old {
public:
    string addBinary(string a, string b) {
        int nStrLengthA=a.size();
        int nStrLengthB=b.size();

        string output;
        int indexA=nStrLengthA-1;
        int indexB=nStrLengthB-1;

        int carry=0;
        int sum=0;

        while(indexA>=0 && indexB>=0){
            sum=((a[indexA]- '0')+(b[indexB]-'0')+carry)%2;  //to_string need C++ 11
            carry=((a[indexA]- '0')+(b[indexB]-'0')+carry)/2;
            output.insert(0,to_string(sum));
            indexA--;
            indexB--;
        };

        //case for b is null
        while(indexA>=0){
            sum=((a[indexA]- '0')+carry)%2;
            carry=((a[indexA]- '0')+carry)/2;
            output.insert(0,to_string(sum));
            indexA--;
        }

        //case for b is null
        while(indexB>=0){
            sum=((b[indexB]-'0')+carry)%2;
            carry=((b[indexB]-'0')+carry)/2;
            output.insert(0,to_string(sum));
            indexB--;
        }

        if(carry==1)
             output.insert(0,to_string(carry));


        return output;    
    }
};

int main(){
    Solution s;
    cout<<s.addBinary("010","101")<<endl;
}