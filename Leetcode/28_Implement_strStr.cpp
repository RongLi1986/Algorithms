/*
Implement strStr() Total Accepted: 28479 Total Submissions: 131240 My Submissions Question Solution 
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. 
If you still see your function signature returns a char * or String, please click the reload button  
to reset your code definition.
*/


/*
travese haystack by i, comparing haystack[i] and needle's first char
if they are same, then start a loop for comparing
each char in needle with haystack.
if reach end of needle return i   
*/


#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
      	int haystackSize=strlen(haystack);
        int needleSize=strlen(needle);
        
        if(needleSize==0)
            if(haystackSize==0)
                return 0;	//for "","" case
        else
        	return 0;

        int i=0;
        while(i<haystackSize){
        	if(haystackSize-i<needleSize)
        		return -1;
        	int j=0;
        	int k=i;
        	while(haystack[k]==needle[j]){
        		if(j==needleSize-1)
        			return i;
        		j++;
        		k++;
        	}
        	i++;
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(haystack.size()==0&&needle.size()==0) //for "","" case
            return 0;
        

        int i=0;
        while(i<haystack.size()){
            if(haystack.size()-i<needle.size())
                return -1;
            int j=0;
            int k=i;
            while(haystack[k]==needle[j]){
                if(j==needle.size()-1) return i;
                j++;
                k++;
            }

            i++;
        }

        return -1;
    }

};

int main(){
	Solution s;
	char* haystack="this is hello world";
	char* needle0="hello";
	char* needle1="ld";
	char* needle2="th";
	char* needle3="helllo";
	cout<<s.strStr(haystack,needle0)<<endl;
	cout<<s.strStr(haystack,needle1)<<endl;
	cout<<s.strStr(haystack,needle2)<<endl;
	cout<<s.strStr(haystack,needle3)<<endl;
	cout<<s.strStr("","")<<endl;
	//cout<<s.strStr(haystack,needle0)<<endl;

	return 0;
}