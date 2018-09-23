/*
Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

/*
each string is create by n-1 one, so 
it use recursive to create n-1th string
create nth string by n-1 string
*/

#include <iostream>
#include <string>
using namespace std; 

class Solution {
public:
    string countAndSay(int n) {
        //corner case
        if(n==0){
            return "0";
        }else if(n==1){
            return "1";
        }

        //find n-1 string
        string s=countAndSay(n-1); 
        int nLength=s.size();
        
        //create nth string
        int i=1;
        int count=1;
        char val=s[0];
        string out;
        while(i<nLength){
          if(s[i]==val){
              count++; 
              i++;
          }else{
              out+=push(count,val);
              val=s[i];
              count=1;
              i++;
          }     
        }
        
        //handle end case(last char and count)
        out+=push(count,val);

        return out;
    }

    string push(int count, char val){
      string s=to_string(count);
      s+=val;
      return s;
    }  
};


int main(){
	Solution sol;
  cout<<sol.countAndSay(0)<<endl;
  cout<<sol.countAndSay(1)<<endl;
  cout<<sol.countAndSay(2)<<endl;
  cout<<sol.countAndSay(3)<<endl;
  cout<<sol.countAndSay(4)<<endl;
  cout<<sol.countAndSay(5)<<endl;
	cout<<sol.countAndSay(6)<<endl;

	return 0;
}
