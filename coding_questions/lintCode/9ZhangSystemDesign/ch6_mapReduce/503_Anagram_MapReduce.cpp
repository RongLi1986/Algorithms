/*
Use Map Reduce to find anagrams in a given list of words.

Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"],["code"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba"], ["cd", "dc"], ["e"].
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
 */
class AnagramMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, string& value);
        while (!input->done()) {
            vector<string> words = findWords(input->value());
            for (string word : words) {
                string tmp = word;
                sort(tmp.begin(), tmp.end());
                output(tmp, word);
            }
            input->next();
        }
    }
    
    vector<string> findWords(string s){
        s+=" ";
        std::size_t found = s.find(" ");
        std::size_t current = 0;
        vector<string> res;
        
        while(found!=std::string::npos){
            string word = s.substr(current, found - current);
            res.push_back(word);
            current =found+1;
            found = s.find(" ", current);
        }
        
        return res;
    }
};


class AnagramReducer: public Reducer {
public:
    void Reduce(string &key, Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to output 
        // the results into output buffer.
        // void output(string &key, vector<string>& value);
        vector<string> res;
        
        //unordered_map<string, bool> hashMap;
        while(!input->done()){
            string content = (input->value());
            res.push_back(content);
            input->next();
        }
        
        output(key, res);
    }
};