/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees 
of every node never differ by more than 1.
 
Given binary tree A={3,9,20,#,#,15,7}, B={3,#,20,15,7}

A)  3            B)    3 
   / \                  \
  9  20                 20
    /  \                / \
   15   7              15  7
The binary tree A is a height-balanced binary tree, but B is not.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(root==NULL) return true;
        
        
        int left=isBalancedHelper(root->left);
        int right=isBalancedHelper(root->right);
        
        if(abs(left-right)>1)
            return false;
        
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    
    int isBalancedHelper(TreeNode* root){
        if(root==NULL) return 0;
        
        int leftHeight=isBalancedHelper(root->left);
        int rightHeight=isBalancedHelper(root->right);
    
            
        return max(leftHeight,rightHeight)+1;
    }
};

int main(){

	return 0;
}