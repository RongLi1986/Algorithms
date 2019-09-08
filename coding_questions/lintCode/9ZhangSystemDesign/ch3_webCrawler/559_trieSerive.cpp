/*
Trie Service 

Build tries from a list of pairs. Save top 10 for each node.

Example
Given a list of

<"abc", 2>
<"ac", 4>
<"ab", 9>
Return <a[9,4,2]<b[9,2]<c[2]<>>c[4]<>>>, and denote the following tree structure:

         Root
         / 
       a(9,4,2)
      /    \
    b(9,2) c(4)
   /
 c(2)
*/

#include <map>
#include <string>

/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 *     vector<int> top10;
 * };
 */
class TrieService {
private:
    TrieNode* root;

public:
    TrieService() {
        root = new TrieNode();
    }

    TrieNode* getRoot() {
        // Return root of trie root, and 
        // lintcode will print the tree struct.
        return root;
    }

    void insert(string& word, int frequency) {
        // Write your code here
        TrieNode* ptr = this->getRoot();
        
        for(int i = 0;i<word.size();i++){
            if((ptr->children).find(word[i]) == (ptr->children).end()){
                //save this char
                TrieNode* tmp = new TrieNode();
                (ptr->children)[word[i]] = tmp;
                (tmp->top10).push_back(frequency);
                sort((tmp->top10).begin(), (tmp->top10).end(), std::greater<int>());
                ptr = tmp;
            }else{
                ptr = (ptr->children)[word[i]];
                (ptr->top10).push_back(frequency);
                sort((ptr->top10).begin(), (ptr->top10).end(), std::greater<int>());
            }
        }
        
        return; 
    }
};

