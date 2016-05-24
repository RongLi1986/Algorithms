/*
Symmetric Binary Tree

Given a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Have you met this question in a real interview? Yes
Example
    1
   / \
  2   2
 / \ / \
3  4 4  3
is a symmetric binary tree.

    1
   / \
  2   2
   \   \
   3    3
is not a symmetric binary tree.
*/


#include <iostream>
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
     * @param root, the root of binary tree.
     * @return true if it is a mirror of itself, or false.
     */
    bool isSymmetric(TreeNode* root) {
        // Write your code here
        if(root==NULL)
            return true;
        
        return check(root->left, root->right);
    }
    
    bool check(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL)
            return true;
        else if(node1==NULL || node2 ==NULL )
            return false;
        else if(node1->val!=node2->val)
            return false;
        else{
            return check(node1->left,node2->right) && check(node1->right,node2->left);
        }
    }
};

int main(){

	return 0;
}