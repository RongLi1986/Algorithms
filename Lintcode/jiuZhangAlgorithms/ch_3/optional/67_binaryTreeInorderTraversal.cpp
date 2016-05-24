/*
Given a binary tree, return the inorder traversal of its nodes' values.
*/


#include <iostream>
using namespace std;

/*
1.recursive
2.todo: non-recursive
*/

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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        
        dfsRecursive(root, res);
        
        return res;
    }
    
    void dfsRecursive(TreeNode *root, vector<int> & res){
        if(root==NULL)
            return;
        
        dfsRecursive(root->left, res);
        res.push_back(root->val);
        dfsRecursive(root->right, res);
        
        return;
    }
};

int main(){

	return 0;
}