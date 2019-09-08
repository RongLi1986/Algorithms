/*
Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

Example
Given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

[
  "1->2->5",
  "1->3"
]
*/


#include <iostream>
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
    vector<string> ans;
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        if(root==NULL) return ans;
        
        string tmp;
        
        binaryTreePathsHelper(root, tmp);
        
        return ans;
    }
    
    void binaryTreePathsHelper(TreeNode* root, string path){
    
        //cout<<root->val<<endl;
        
        if(path.empty()){ //first node
            path = to_string(root->val);
        }else{
            path += "->";
            path += to_string(root->val); 
        }
        
        //cout<<path<<endl;
        
        if(root->left!=NULL){
            binaryTreePathsHelper(root->left, path);
            
        }
        
        if(root->right!=NULL){
            binaryTreePathsHelper(root->right, path);
        }
        
        //end of path
        if(root->right==NULL && root->left==NULL){
            //cout<<path<<endl;
            ans.push_back(path);
        }
        
        return;
    }
};