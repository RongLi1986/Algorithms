/*
Add and Search Word - Data structure design 
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    vector<TrieNode*> childrenList;
    char value;
    bool end;
    // Initialize your data structure here.
    TrieNode() {
        value='R';
    }

    TrieNode(char s){
        value=s;
        end=false;
    }
};
//not fast
class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* ptr=root;
        bool find=false;
        for(int i=0;i<word.size();i++){
            for(int j=0;j<ptr->childrenList.size();j++){
                if(ptr->childrenList[j]->value==word[i]){
                    ptr=ptr->childrenList[j];
                    find=true;
                    break;
                }
            }
            if(find==false){
                TrieNode* childrenNode=new TrieNode(word[i]);
                ptr->childrenList.push_back(childrenNode);
                //cout<<childrenNode->value<<endl;
                ptr=childrenNode;
            }else
                find=false;

            if(i==word.size()-1) ptr->end=true;

        }
        //cout<<"insert "<<s<<endl;
        return;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search_single(root, word, 0);
    }

    bool search_single(TrieNode* node, string str, int index) {
        
        if(index>=str.size()) {
            //cout<<node->value<<endl;
            if(node->end==true)
                return true;
            return false;
        }

        bool find=false;

        int childrenNum=node->childrenList.size();
        
        if(str[index]=='.'){

            for(int j=0;j<childrenNum;j++){
                //cout<<node->childrenList.size()<<" "<<j<<endl;
                TrieNode* ptr=node->childrenList[j]; //node should not change
                find|=search_single(ptr,str,index+1);
                //cout<<"find is"<<find<<endl;
                if(find==true)
                    return true;
                //cout<<"j is "<<j<<endl;
            }
        }
        else{ 
            for(int j=0;j<childrenNum;j++){

                //cout<<node->childrenList[j]->value<<endl;
                if(node->childrenList[j]->value==str[index]){
                    
                    node=node->childrenList[j];
                    find=true;
                    return search_single(node,str,index+1);
                }
            }
        }
        
        if(find==false) 
            return false;
        return true;
    }    
    
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(){
    WordDictionary s;
    //s.addWord("at");
    //s.addWord("and");
    //s.addWord("an");
    
    s.addWord("add");
    //cout<<s.search("pad")<<endl; //-> false
    //cout<<s.search("bad")<<endl; //-> true
    cout<<s.search(".at")<<endl; //-> true
    //cout<<s.search("b..")<<endl; //-> true
    s.addWord("bat");
    cout<<s.search(".at")<<endl; 

    //addWord("at"),addWord("and"),addWord("an"),addWord("add"),search("a"),search(".at"),addWord("bat"),search(".at"),search("an."),search("a.d."),search("b."),search("a.d"),search(".")

    return 0;
}