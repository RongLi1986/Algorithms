/*
Length of Last Word 
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
#include <iostream>
using namespace std;


/*
first kill last space
if it has only space, return 0
then travsal string find last space index
and return length-1-(index)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if(s.empty()) return 0;
        
        //leetcode has case that last char is space
        //so we kill it first
        int i=s.size()-1;
        while(s[i]==' ') {
            i--;
            //" " only has space
            if(i<0) 
                return 0;
        }
        
        int length=i+1;
        int spaceIndex=-1;
        for(int i=0;i<length;i++){
            if(s[i]==' ')
                spaceIndex=i;
        }
        
        //no space, one word
        if(spaceIndex==-1) return length;
        
        return length-1-spaceIndex;
    }
};


//rule maybe changed
class Solution_old {
public:
    int lengthOfLastWord(const char *s) {
		if(s==NULL) 
			return 0;
		
		int i=0;
		int last_Length=0;
		int nLength=0;
		int flag=0;  //flag for in word or not
		while(1){
			if(s[i]==' '){
				last_Length=nLength;
				flag=0;
			}else if(s[i]=='\0'){
				flag=0;
				last_Length=nLength;
				nLength=0;
				return last_Length;
			}else{
				if(flag==1)
					nLength++;
				else{
					nLength=1;
					flag=1;
				}
			}
			
			i++;
		} 
	
    }
};

int main(){
	Solution s;
	
	cout<<s.lengthOfLastWord("hello world")<<endl;  //5
	cout<<s.lengthOfLastWord("hellooo")<<endl;  //7
	cout<<s.lengthOfLastWord("     hel")<<endl;  //3
	cout<<s.lengthOfLastWord("hellooo  ")<<endl;  //0

	return 0;
}