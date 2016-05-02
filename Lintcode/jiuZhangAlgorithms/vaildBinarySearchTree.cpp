/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
A single node tree is a BST
 */

#include <iostream>
using namespace std;

/*
inorder traversal + check array whether increasig or not 
 */

class Solution {
private:
    vector<int> res;
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        res=inorderTraversal(root);
        
        for(int i=0;i<res.size();i++){
            if(i<res.size()-1 && res[i]>=res[i+1])
                return false;
        }
        
        return true;
        
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        
        inorderTraversalRecursive(root);
        
        return res;
    }
    
    void inorderTraversalRecursive(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorderTraversalRecursive(root->left);
        res.push_back(root->val);
        inorderTraversalRecursive(root->right);
        
        return;
    }
};

int main(){

	return 0;
}