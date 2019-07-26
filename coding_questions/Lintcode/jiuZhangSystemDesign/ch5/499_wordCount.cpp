/*
Using map reduce to count word frequency.

https://hadoop.apache.org/docs/r1.2.1/mapred_tutorial.html#Example%3A+WordCount+v1.0

Example
chunk1: "Google Bye GoodBye Hadoop code"
chunk2: "lintcode code Bye"


Get MapReduce result:
    Bye: 2
    GoodBye: 1
    Google: 1
    Hadoop: 1
    code: 2
    lintcode: 1
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

class WordCountMapper: public Mapper {
public:
    void Map(Input<string>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        while(!input->done()){
            string s = input->value();
            //vector<string> words = findWords(s);
            vector<string> words = split(s, " ");
            
            for(int i=0;i<words.size();i++){
                //cout<<words[i]<<endl;
                output(words[i], 1);
            }
            input->next();
        }
        
        return;
    }
    
    vector<string> findWords(string& s){
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



class WordCountReducer: public Reducer {
public:
    void Reduce(string &key, Input<int>* input) {
        // Write your code here
        // Please directly use func 'output' to 
        // output the results into output buffer.
        // void output(string &key, int value);
        int sum = 0;
        while (!input->done()) {
            sum += input->value();
            input->next();
        }
        
        output(key, sum);
    }
};

int main(){

    return 0;
}