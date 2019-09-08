/*
Top K Frequent Words

 Description
 Notes
 Testcase
 Judge
Given a list of words and an integer k, return the top k frequent words in the list.

 Notice

You should order the words by the frequency of them in the return list, the most frequent one comes first. If two words has the same frequency, the one with lower alphabetical order come first.

Have you met this question in a real interview? Yes
Example
Given

[
    "yes", "lint", "code",
    "yes", "code", "baby",
    "you", "baby", "chrome",
    "safari", "lint", "code",
    "body", "lint", "code"
]
for k = 3, return ["code", "lint", "baby"].

for k = 4, return ["code", "lint", "baby", "yes"],
*/

struct mycomparsion{
    bool operator() (const pair<string, int>& lhs, const pair<string, int>&rhs) const
    {
            if(lhs.second==rhs.second)
                return (lhs.first>rhs.first);
            return (lhs.second<rhs.second);
    }
};

class Solution {
public:
    /**
     * @param words an array of string
     * @param k an integer
     * @return an array of string
     */
    vector<string> topKFrequentWords(vector<string>& words, int k) {
        // Write your code here
        unordered_map<string, int> hashMap;
        priority_queue<pair<string, int>, vector<pair<string, int> >, mycomparsion > pQueue;
        vector<string> res;
        for(int i=0;i<words.size();i++){
            if(hashMap.find(words[i])==hashMap.end()){
                hashMap[words[i]]=1;
            }else{
                hashMap[words[i]]++;
            }
        }
        
        unordered_map<string, int>::iterator it= hashMap.begin();
        for(;it!=hashMap.end();it++){
            pair<string, int> node((*it).first, (*it).second);
            pQueue.push(node);
        }
        
        int i=0;
        while(i<k && !pQueue.empty()){
            res.push_back(pQueue.top().first);
            pQueue.pop();
            i++;
        }
        
        return res;
    }
};