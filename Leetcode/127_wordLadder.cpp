/*
Word Ladder Total Accepted: 39281 Total Submissions: 204285 My Submissions Question Solution 
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/* 
bfs find stard word to end word level
changing word we could loop word's each char poisiton and change it 
to other 25 letters.
make a pair for keep the level counts
*/ 


#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>  //pair

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		wordDict.insert(endWord);
		queue<pair<string,int> > q;
        q.push(make_pair(beginWord,1));
        while(!q.empty()) {
        	string s=q.front().first;
        	int len=q.front().second;
        	if(s==endWord) return len;
        	q.pop();
        	vector<string> neigborlist=findString(s,wordDict);

        	for(int i=0;i<neigborlist.size();i++){
        		pair<string,int> tmp=make_pair(neigborlist[i],len+1);
        		q.push(tmp);
        	}

        }

        return 0;
    }

    vector<string> findString(string s, unordered_set<string>& wordDict){
    	int length=s.size();
    	vector<string> out;
    	for(int i=0;i<length;i++){
    		for(int j=0;j<26;j++){
    			string tmp=s;
    			tmp[i]='a'+j;
    			if(wordDict.find(tmp)!=wordDict.end()){
    				out.push_back(tmp);
    				wordDict.erase(tmp); //make visit
    			}
    		}
    	}

    	return out;
    }
};


int main(){
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict = {"hot","dot","dog","lot","log"};

	Solution s;
	cout<<s.ladderLength(start,end,dict)<<endl;
	return 0;
}