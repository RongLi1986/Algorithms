/*
Use map reduce to build inverted index for given documents.
*/

/*

*/

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * Definition of Input:
 * template<class T>
 * class Input {
 * public:
 *     bool done(); 
 *         // Returns true if the iteration has elements or false.
 *     void next();
 *         // Move to the next element in the iteration
 *         // Runtime error if the iteration has no more elements
 *     T value();
 *        // Get the current element, Runtime error if
 *        // the iteration has no more elements
 * }
 * Definition of Document:
 * class Document {
 * public:
 *     int id; // document id
 *     string content; // document content
 * }
 */

class InvertedIndexMapper: public Mapper {
public:
    void Map(Input<Document>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, int value);
        
        while(!input->done()){
            string content = (input->value()).content;
            content += ' ';
            int n = content.size();
            string tmp;
            for (int i = 0; i < n; ++i) {
                if (content[i] == ' ') {
                    if (tmp.length() > 0)
                        output(tmp, (input->value()).id);
                    tmp.clear();
                } else
                    tmp+=content[i];
            }
            input->next();
        }
    }
};


class InvertedIndexReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, vector<int> &value);
        vector<int> res;
        unordered_map<int,bool> hashMap;
        while(!input->done()){
            int val = input->value();
            if(hashMap.find(val) == hashMap.end()){
                res.push_back(val);
                hashMap[val]=true;
            }
            input->next();
        }
        
        sort(res.begin(),res.end());
        output(key, res);
        
    }
};

int main(){

    return 0;
}