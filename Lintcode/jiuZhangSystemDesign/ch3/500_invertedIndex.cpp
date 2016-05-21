/*
Create an inverted index with given documents.

Notice
Ensure that data does not include punctuation.

Example
Given a list of documents with id and content. (class Document)

[
  {
    "id": 1,
    "content": "This is the content of document 1 it is very short"
  },
  {
    "id": 2,
    "content": "This is the content of document 2 it is very long bilabial bilabial heheh hahaha ..."
  },
]
Return an inverted index (HashMap with key is the word and value is a list of document ids).

{
   "This": [1, 2],
   "is": [1, 2],
   ...
}
*/

#include <map>
#include <string>

/**
 * Definition of Document:
 * class Document {
 * public:
 *     int id;
 *     string content;
 * }
 */

class Solution {
public:
    /**
     * @param docs a list of documents
     * @return an inverted index
     */
    map<string, vector<int>> invertedIndex(vector<Document>& docs) {
        // Write your code here
        map<string, vector<int> > treeMap;
        unordered_map<string, bool> visitedMap;
        
        for(int i=0;i<docs.size();i++){
            visitedMap.clear();
            string content=docs[i].content;
            istringstream iss(content);
            
            do{
                string subStr;
                iss >> subStr;
                if(!subStr.empty()){
                    if(treeMap.find(subStr)==treeMap.end()){
                        treeMap[subStr] = vector<int>();
                        
                        if(visitedMap.find(subStr)==visitedMap.end()){
                            treeMap[subStr].push_back(docs[i].id);
                            visitedMap[subStr] = true;
                        }
                    }else{
                        if(visitedMap.find(subStr)==visitedMap.end()){
                            treeMap[subStr].push_back(docs[i].id);
                            visitedMap[subStr] = true;
                        }
                    }
                    //cout << "Substring: " << subStr << endl;
                }
            }while (iss);
        }
        
        return treeMap;
    }
};

int main(){

	return 0;
}