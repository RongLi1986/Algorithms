/*
Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from 
the root node down to the nearest leaf node.
*/


#include <iostream>
using namespace std;

/*
leaf node must exist.
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if(root==NULL)  //no leaf case
            return 0;
        else if(root->left==NULL && root->right == NULL)
            return 1;
        else if(root->left==NULL){
            return minDepth(root->right)+1;
        }else if(root->right == NULL){
            return minDepth(root->left)+1;
        }else{
            int depthLeft = minDepth(root->left)+1;
            int depthRight = minDepth(root->right)+1;
            return min(depthLeft,depthRight);
        }
        
    }
};

int main(){

	return 0;
}