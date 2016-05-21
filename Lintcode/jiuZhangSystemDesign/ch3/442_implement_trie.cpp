/*
Implement a trie with insert, search, and startsWith methods.

Notice:
You may assume that all inputs are consist of lowercase letters a-z.

Example
insert("lintcode")
search("code") // return false
startsWith("lint") // return true
startsWith("linterror") // return false
insert("linterror")
search("lintcode) // return true
startsWith("linterror") // return true
*/

#include <map>
#include <string>

/*
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */

class TrieNode {
private:
    int startFlag;
    int endFlag;
    char c;
    unordered_map<char,TrieNode*> childrenBranch;
public:
    // Initialize your data structure here.
    TrieNode() {
        startFlag = true;
        endFlag = false;
    }
    
    TrieNode(char in) {
        c = in;
        startFlag = false;
        endFlag = false;
    }
    

    char getChar(){
        return c;
    }
    
    void setEnd(){
        endFlag = true;
    }
    
    bool getEnd(){
        return endFlag;
    }
    
    unordered_map<char,TrieNode*>& getChildBranchs(){
        return childrenBranch;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* ptr = root;
        for(int i=0;i<word.size();i++){
            if((ptr->getChildBranchs()).find(word[i])==(ptr->getChildBranchs()).end()){
                TrieNode* node = new TrieNode(word[i]);
                (ptr->getChildBranchs())[word[i]] = node;
                ptr=node;
            }else{
                TrieNode* node=(ptr->getChildBranchs())[word[i]];
                ptr=node;
            }
            
        }
        
        ptr->setEnd();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* ptr = root;
        for(int i=0;i<word.size();i++){
            if((ptr->getChildBranchs()).find(word[i])==(ptr->getChildBranchs()).end()){
                return false;
            }else{
                TrieNode* node=(ptr->getChildBranchs())[word[i]];
                ptr=node;
            }
        }
        
        if(ptr->getEnd())
            return true;
        
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for(int i=0;i<prefix.size();i++){
            if((ptr->getChildBranchs()).find(prefix[i])==(ptr->getChildBranchs()).end()){
                return false;
            }else{
               TrieNode* node=(ptr->getChildBranchs())[prefix[i]];
               ptr=node;
            }
        }
        
        return true;
    }

private:
    TrieNode* root;
};

int main(){

	return 0;
}