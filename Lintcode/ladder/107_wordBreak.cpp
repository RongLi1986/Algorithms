/*
Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.

Given s = "lintcode", dict = ["lint", "code"].

Return true because "lintcode" can be break as "lint code".
*/

/*
DP:
define a vector s that sub string could segmented by dict

s[i] =1  : string[0,i] could be find in dict
          or string[0,j]=1 and string[j+1, i] could find in dict
s[i] =0  means it or its substr cannot be segmented.

after scan, return s[string.size()-1]
*/

#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        vector<bool> maps(s.size()+1,false);
        maps[0]=1;
        
        for(int i=1;i<maps.size();i++){
            for(int j=i-1;j>=0;j--){
                if(i-j>20)  //word length check
                    break;  //normally, word length should smaller than 20 
                    
                if(maps[j]==true && dict.find(s.substr(j,i-j))!=dict.end()){
                    maps[i]=true;
                    break;
                }
            }
        }
        
        return maps[s.size()];
    }
};


int main(){

	return 0;
}