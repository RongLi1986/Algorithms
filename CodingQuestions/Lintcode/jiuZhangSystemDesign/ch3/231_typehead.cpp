/*
mplement typeahead. Given a string and a dictionary, return all words that contains the string as a substring. 
The dictionary will give at the initialize method and wont be changed. 
The method to find all words with given substring would be called multiple times.

Example
Given dictionary = {"Jason Zhang", "James Yu", "Bob Zhang", "Larry Shi"}

search "Zhang", return ["Jason Zhang", "Bob Zhang"].

search "James", return ["James Yu"].
*/

#include <map>
#include <string>

class Typeahead {
private:
    unordered_set<string> dictory; 
public:
    // @param dict: A dictionary of words dict
    Typeahead(unordered_set<string> &dict) {
        // do initialize if necessary
        dictory = dict;
    }
    
    // @param str: a string
    // @return a set of words
    vector<string> search(string &str) {
        // Write your code here
        vector<string> res;
        
        for(unordered_set<string>::iterator it=dictory.begin();it!=dictory.end();++it){
            //if(subString(*it,str)){
            std::size_t found = (*it).find(str);
            if(found!=std::string::npos){
                res.push_back(*it);
            }
        }
        
        return res;
    }
};

//use hashmap keep every possible sub str
class Typeahead {
private:
    //unordered_set<string> dictory; 
    unordered_map <string,vector<string> > hashMap;
public:
    // @param dict: A dictionary of words dict
    Typeahead(unordered_set<string> &dict) {
        // do initialize if necessary
        for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();++it){
            //if(subString(*it,str)){
            int len = (*it).size();
            for (int i = 0; i < len; ++i)
                for (int j = i + 1; j <= len; ++j) {
                    string tmp = (*it).substr(i, j - i);
                    if (hashMap.find(tmp) == hashMap.end()) {
                        hashMap[tmp] = vector<string>();
                        hashMap[tmp].push_back(*it);
                    } else {
                        //???
                        if(hashMap[tmp][hashMap[tmp].size()-1]!=(*it))
                            hashMap[tmp].push_back(*it);
                    }
                }
        }
    }
    
    // @param str: a string
    // @return a set of words
    vector<string> search(string &str) {
        // Write your code here
        
        if(hashMap.find(str)!=hashMap.end())
            return hashMap[str];
        else 
            return vector<string>();
    }
};



int main(){

	return 0;
}