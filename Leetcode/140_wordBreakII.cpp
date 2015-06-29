/*
Word Break II Total Accepted: 32710 Total Submissions: 186666 My Submissions Question Solution 
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
	vector<string> out;
public:
	vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
		unordered_map<string, vector<string>> hsMap;
		return wordBreakHelper(s,wordDict,hsMap);
	}

	vector<string> wordBreakHelper(string s, set<string> wordDict, unordered_map<string, vector<string> > hsMap){
		if(hsMap,find(s)!=hsMap.end()) return hsMap[s];
        vector<string> result;
        int n = s.size();
        if(n <= 0) return result;
        for(int len = 1; len <= n; ++len){
            string subfix = s.substr(0,len);
            if(wordDict.find(subfix)!=wordDict.end()){
                if(len == n){
                    result.push_back(subfix);
                }else{
                    string prefix = s.substr(len,s.size()-len);
                    vector<string> tmp = wordBreakHelper(prefix, wordDict, hsMap);
                    string item;
                    for(int i=0;i<tmp.size();i++){
                    	item=tmp[i];
                        item = subfix + " " + item;
                        result.add(item);
                    }
                }
            }
        }
        hsMap[s]= result;
        return result;
	}
};

int main(){



	return 0;
}