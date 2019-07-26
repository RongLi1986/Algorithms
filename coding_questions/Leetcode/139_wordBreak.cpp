/*
Word Break Total Accepted: 49986 Total Submissions: 219049 My Submissions Question Solution 
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
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
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> breakArray(s.size(),0);
        for(int i=0;i<s.size();i++){
            if(wordDict.find(s.substr(0,i+1))!=wordDict.end()){
                breakArray[i]=1;
            }else{
                for(int j=0;j<i;j++){
                    if(breakArray[j]==1 && wordDict.find(s.substr(j+1,i-j))!=wordDict.end()){
                        breakArray[i]=1;
                        break;
                    }
                }
            }
        }
        
        return breakArray[s.size()-1];
    }
};

class Solution_same {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		    vector<bool> wordB(s.length() + 1, false);
		    wordB[0] = true;
		    for (int i = 1; i < s.length() + 1; i++) {
		        for (int j = i - 1; j >= 0; j--) {
		            if (wordB[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
		                wordB[i] = true;
		                break; //只要找到一种切分方式就说明长度为i的单词可以成功切分，因此可以跳出内层循环。
		            }
		        }
		    }
		    return wordB[s.length()];
	}
};


int main(){

	return 0;
}