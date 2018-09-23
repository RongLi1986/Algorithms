/*
Binary Tree Serialization
Design an algorithm and write code to serialize and deserialize a binary tree. 
Writing the tree to a file is called 'serialization' and reading back from the file 
to reconstruct the exact same binary tree is 'deserialization'.

There is no limit of how you deserialize or serialize a binary tree, 
you only need to make sure you can serialize a binary tree to a string 
and deserialize this string to the original structure.

Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

  3
 / \
9  20
  /  \
 15   7
Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

You can use other method to do serializaiton and deserialization.
*/

/*
serialize: preorder dfs...for every NULL node use "#"
deserialize :preorder traversal
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
private:
    int index;
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string s;
        dfsPreorder(root,s);
        
        return s;
    }
    
    void dfsPreorder(TreeNode* root, string& s){
        if(root==NULL){
            s+="#";
            return;
        }else{
            s+='0'+root->val;
            dfsPreorder(root->left,s);
            dfsPreorder(root->right,s);
        }
    }
    

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        //cout<<data<<endl;
        index=0;
        TreeNode* root = buildTree(data);     
        
        return root;
    }
    
    TreeNode* buildTree(string data){
        if(index>=data.size())
            return NULL;
        else if(data[index]=='#'){
            return NULL;
        }else{
            TreeNode* tmp = new TreeNode(data[index]-'0');
            index++;
            tmp->left=buildTree(data);
            index++;
            tmp->right=buildTree(data);
            return tmp;
        }
    }
};


int main(){
	
	return 0;
}