/*
Word Break II

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Have you met this question in a real interview? Yes
Example
Gieve s = lintcode,
dict = ["de", "ding", "co", "code", "lint"].

A solution is ["lint code", "lint co de"].
*/

/*

*/
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
        unordered_map<string, vector<string>> hsMap;
        return wordBreakHelper(s,wordDict,hsMap);
    }

    vector<string> wordBreakHelper(string &s, unordered_set<string> &wordDict, unordered_map<string, vector<string> > &hsMap){
        if(hsMap.find(s)!=hsMap.end()) return hsMap[s];
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
                    //string item;
                    for(string item:tmp){
                        //item=tmp[i];
                        item = subfix + " " + item;
                        result.push_back(item);
                    }
                }
            }
        }
        hsMap[s]= result;
        return result;
    }
};