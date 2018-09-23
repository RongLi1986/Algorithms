/*
Serialize and deserialize a trie (prefix tree, search on internet for more details).

You can specify your own serialization algorithm, the online judge only cares about whether 
you can successfully deserialize the output from your own serialize function.

Example:
str = serialize(old_trie)
>> str can be anything to represent a trie
new_trie = deserialize(str)
>> new_trie should have the same structure and values with old_trie
An example of test data: trie tree <a<b<e<>>c<>d<f<>>>>, denote the following structure:

     root
      /
     a
   / | \
  b  c  d
 /       \
e         f

*/
#include <map>
#include <string>

/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 * };
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a trie which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TrieNode* root) {
        // Write your code here
        if (root == NULL)
            return "";
        string data;
        for (map<char, TrieNode*>::iterator it = root->children.begin();
        it != root->children.end(); ++it) {
            data += it->first;
            data += serialize(it->second);
        }
        
        return "<" + data + ">";
    }


    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TrieNode* deserialize(string data) {
        // Write your code here
        TrieNode* root= new TrieNode();
        TrieNode* current = root;
        
        stack<TrieNode* > stk;
        //cout<<"ss"<<endl;
        for(int i=0;i<data.size();i++){
            //cout<<data[i]<<endl;
            if(data[i]=='<'){
                stk.push(current);
            }else if(data[i] == '>'){
                stk.pop();
                if(!stk.empty())
                    current=stk.top();
            }else{
                TrieNode* child= new TrieNode();
                current->children[data[i]]=child;
                current=child;
            }
        }
        //cout<<"hh"<<endl;
        return root;
        
    }
};

int main(){

	return 0;
}