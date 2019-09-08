/*
Word Ladder

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
 Notice

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.


Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/

/*
bfs
*/

class Solution {
/**
  * @param start, a string
  * @param end, a string
  * @param dict, a set of string
  * @return an integer
  */
private:
    unordered_map<string, bool > visitMap;
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        dict.insert(end);
        queue<pair<string,int > >q;
        q.push(make_pair(start,1));
        while(!q.empty()) {
            string s=q.front().first;
            int length = q.front().second;
            
            if(s==end) {
                return length;
            }
            
            q.pop();
            vector<string> neigborlist=findString(s,end,dict);
            
            for(int i=0;i<neigborlist.size();i++){
                pair<string,int > tmp=make_pair(neigborlist[i],length+1);
                visitMap[tmp.first] = true;
                q.push(tmp);
            }
        }
 
        return 0;
    }
    
    vector<string> findString(string s, string end, unordered_set<string>& wordDict){
        int length=s.size();
        vector<string> out;
        if(s==end) return out;
        for(int i=0;i<length;i++){
            for(int j=0;j<26;j++){
                string tmp=s;
                tmp[i]='a'+j;
                if(visitMap.find(tmp)==visitMap.end()){
                    if(wordDict.find(tmp)!=wordDict.end()){
                        out.push_back(tmp);
                        //if(tmp!=end)
                        //wordDict.erase(tmp);
                    }
                }
            }
        }
 
        return out;
    }
};