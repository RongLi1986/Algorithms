/*
Longest Substring Without Repeating Characters 
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include <iostream>
#include <string>
#include <map>
#include <cstring> 
using namespace std;

class Solution {
public:
	//map TLE
    int lengthOfLongestSubstring_map(string s) {
        map<char,int> mymap;
        int i=0;
        int size=s.size();
        int count=0;
        int out=0;
        int substringID=0;
        while(i<size){
        	if(mymap.find(s[i])!=mymap.end()){
        		if(count>out)
        			out=count;
        		
        		substringID=0;
        		i=i-count+mymap.find(s[i])->second;
        		mymap.clear();
        		count=0;
        		//map<char,int>::iterator it=mymap.begin();
        		//mymap.insert(it, pair<char,int>(s[i],substringID));
        	}else{
        		map<char,int>::iterator it=mymap.begin();
        		mymap.insert(it, pair<char,int>(s[i],substringID));
        		count++;
        		substringID++;
        		//cout<<"jj"<<endl;
        	}
        	i++;
        }

        //last character handle
        if(count>out)
        	out=count;

        return out;
    }
    
    // array
    int lengthOfLongestSubstring(string s) {
        int mymap[256];
        //memset(mymap,-1,256);
        mymemset(mymap, -1, 256);
        int i=0;
        int size=s.size();
        int count=0;
        int out=0;
        int substringID=0;
        while(i<size){
        	//cout<<mymap[s[i]]<<endl;
        	if(mymap[s[i]]!=-1){
        		if(count>out)
        			out=count;
        		
        		substringID=0;
        		i=i-count+mymap[s[i]];
        		mymemset(mymap, -1, 256);
        		count=0;
        	}else{
        		mymap[s[i]]=substringID;
        		count++;
        		substringID++;
        		//cout<<"jj"<<endl;
        	}
        	i++;
        }

        //last character handle
        if(count>out)
        	out=count;

        return out;
    } 

    void mymemset(int a[], int value, int length){
    	int i=0;
    	while(i<length){
    		a[i]=value;
    		i++;
    	}
    }
};


/*
this way I found from discuss, it use a array for keep char's index
this char is repeated char. then it start travese string, and keep 
last repeat char index. if it find repeated char, update repeated index
. for each loop step, caculate i - lastRepeatedIndex. (save max length)

although it same idea with me, it only has 9 line, and faster since it only 
use array for hashing property
*/

class Solution_review {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256];
        fill(m, m+256, -1);  //c++ way to inital array
        int maxLen = 0, lastRepeatPos = -1;  //last repeat postion
        for(int i=0; i<s.size(); i++) {
            if (m[s[i]]!=-1 && lastRepeatPos < m[s[i]]) //this num is repeat one
                                                        // and lastRepeatPos < m[s[i]] ("abba" case)
                lastRepeatPos = m[s[i]];                 //update repeating pos
            if ( i - lastRepeatPos > maxLen ) maxLen = i - lastRepeatPos;  //update maxLen
            m[s[i]] = i;
        }
        return maxLen;
    }
};

int main(){
	Solution s;
	cout<<s.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco")<<endl;

	return 0;
}