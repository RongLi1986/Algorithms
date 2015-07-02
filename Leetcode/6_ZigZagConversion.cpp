/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/*
数学题。巨无聊的一道题，
n=4
P           I             N
A         L S         I   G
Y   A       H    R
P           I

N=5
P             H
A          S  I
Y      I      R
P   L         I  G
A             N


*/


#include <iostream>
#include <string>

using namespace std;

//this way is preety good
class Solution {
public:
    string convert(string s, int nRows) {
        string sc[nRows];
        int nLength=s.size();
        int strIndex=0;
        int colIndex=0;
        if(nLength<=nRows||nRows==1)
            return s;

        while(strIndex<nLength){
            int module=colIndex%(nRows-1);
            if(module==0){                   //put all
                for(int i=0;i<nRows;i++){
                    sc[i].push_back(s[strIndex]);
                    strIndex++;
                    if(strIndex==nLength)    //for"ABCD",2 case, strIndex out s
                        break;
                }
            }else{ //put one
                sc[nRows-1-module].push_back(s[strIndex]);
                strIndex++;
                if(strIndex==nLength)        //for"ABCD",2 case, strIndex out s  
                    break;
            }
            colIndex++;
        }

        string output;


        for(int i=0;i<nRows;i++){
            output+=sc[i];
        }
        
        return output; 
    }
};


int main(){
	Solution s;
	cout<<s.convert("ABCDEFGHIJKLMNOP", 6)<<endl;

	return 0;
}