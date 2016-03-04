/*
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
*/

/*

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
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(root==NULL) 
            return NULL;
        
        if(root == A) 
            return A;
        if(root == B)
            return B;
        
        if( (findNode(root->left,A)&&findNode(root->right,B)) || (findNode(root->right,A)&&findNode(root->left, B)) )
            return root;
        else if(findNode(root->left,A) && findNode(root->left,B))
            return lowestCommonAncestor(root->left, A, B);
        else if(findNode(root->right,A) && findNode(root->right,B))
            return lowestCommonAncestor(root->right, A, B);
        
        return NULL;
    }
    
    bool findNode(TreeNode* root, TreeNode* target){
        if(root == NULL)
            return false;
        else if ( root == target )
            return true;
        else
            return findNode(root->left, target) || findNode(root->right, target);
    }
};

int main(){
	
	return 0;
}