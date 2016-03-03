/*
Given a binary tree, find the maximum path sum from root.

The path may end at any node in the tree and contain at least one node in it.
 */


#include <iostream>
using namespace std;

/*
divided and conque
it will has negative number in tree.
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
     * @param root the root of binary tree.
     * @return an integer
     */
    int maxPathSum2(TreeNode *root) {
        // Write your code here
        if(root==NULL)
            return 0;
        int leftVal = maxPathSum2(root->left);
        int rightVal = maxPathSum2(root->right);
        
        if(leftVal>=0 || rightVal>=0)
            return max(leftVal,rightVal)+root->val;
        else if(leftVal<0 && rightVal<0)
            return root->val;
    }
};

int main(){

	return 0;
}