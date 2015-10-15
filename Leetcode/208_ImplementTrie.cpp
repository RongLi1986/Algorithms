/*
Implement Trie (Prefix Tree) Total Accepted: 3217 Total Submissions: 13057 My Submissions Question Solution 
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/


/*
tips:
use a vector to keep children, and a bool var as end marker.
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
    }

    TrieNode(char s){
        value=s;
        end=false;
    }
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        if(s.empty()) return;
        TrieNode* ptr=root;
        bool found=false;
        for(int i=0;i<s.size();i++){
            vector<TrieNode*>& tmp=ptr->childrenList;
            for(int j=0;j<tmp.size();j++){
                if(tmp[j]->value==s[i]){
                    ptr=tmp[j];  
                    found=true;
                    break;
                }
            }
            
            if(found==false){
                TrieNode* inNode=new TrieNode(s[i]);
                tmp.push_back(inNode);
                ptr=inNode;
            }
            found=false;
        }
        
        ptr->end=true;
        
        return;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if(key.empty()) return false;
        TrieNode* ptr=root;
        bool found=false;
        for(int i=0;i<key.size();i++){
            vector<TrieNode*> &tmp=ptr->childrenList;
            for(int j=0;j<tmp.size();j++){
                if(tmp[j]->value==key[i]){
                    ptr=tmp[j];    
                    found=true;
                    break;
                }
            }
            if(found==false)
                return false;
                
            found=false;
            
        }
        
        return ptr->end==true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.empty()) return false;
        TrieNode* ptr=root;
        bool found=false;
        for(int i=0;i<prefix.size();i++){
            vector<TrieNode*>& tmp=ptr->childrenList;
            for(int j=0;j<tmp.size();j++){
                if(tmp[j]->value==prefix[i]){
                    ptr=tmp[j];    
                    found=true;
                    break;
                }
            }
            if(found==false){
                return false;
            }
                
            found=false;
        }
        
        return true;    
    }

private:
    TrieNode* root;
};



// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){
    Trie trie;
    //trie.insert("somestring");
    //trie.insert("good");
    trie.insert("abc");

    //cout<<trie.search("somestring")<<endl;
    //cout<<trie.search("key")<<endl;
    //cout<<trie.search("good")<<endl;
    cout<<trie.search("abc")<<endl;
    cout<<trie.search("ab")<<endl;
    trie.insert("ab");
    //cout<<trie.startsWith("som")<<endl;
    cout<<trie.search("ab")<<endl;
    
    trie.insert("ab");
    //cout<<trie.startsWith("som")<<endl;
    cout<<trie.search("ab")<<endl;
    cout<<trie.search("a")<<endl;

    //cout<<trie.startsWith("go")<<endl;

    return 0;
}