/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */


/*
recursive and keep depth's value, find larger one from left leaf and right leaf
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if(root==NULL) return 0;
        
        return maxDepth(root,0);
        
    }
    
    int maxDepth(TreeNode *root, int depth){
        if(root==NULL) return depth;
        return max(maxDepth(root->left,depth+1),maxDepth(root->right,depth+1));
    }
};

int main(){

	return 0;
}