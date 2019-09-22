/*
http://www.lintcode.com/en/problem/implement-trie/
http://www.jiuzhang.com/solutions/trie/
 
Implement a Trie with insert, search, and startsWith methods.

Input:
  insert("lintcode")
  search("lint")
  startsWith("lint")
Output:
  false
  true
*/

class TrieNode {
public:
    TrieNode() {
        isString = false;
    }
    map<char, TrieNode*> children;
    bool isString;
};
 
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
 
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++){
            if (p->children.find(word[i]) == p->children.end()) {
                p->children[word[i]] = new TrieNode();
            }
            p = p->children[word[i]];
        }
        p->isString = true;
    }
 
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++){
            if(p == NULL) return false;
            if (p->children.find(word[i]) != p->children.end())
                p = p->children[word[i]];
            else
                p = NULL;
        }
        if(p == NULL || p->isString == false) return false;
        return true;
         
    }
 
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(int i = 0; i < prefix.size(); i++) {
            if (p->children.find(prefix[i]) != p->children.end())
                p = p->children[prefix[i]];
            else
                p = NULL;
                
            if(p == NULL) return false;
        }
        return true;
    }
    
    static string toString(TrieNode* root) {
        if (root == NULL)
            return "";
        string data;
        for (map<char, TrieNode*>::iterator it = root->children.begin();
             it != root->children.end(); ++it) {
            data += it->first;
            data += toString(it->second);
        }
        return "<" + data + ">";
    }

private:
    TrieNode* root;
};
