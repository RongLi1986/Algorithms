/*
Check two given binary trees are identical or not. Assuming any number of tweaks are allowed. A tweak is defined as a swap of the children of one node in the tree.

Notice
There is no two nodes with the same value in the tree.

Example
    1             1
   / \           / \
  2   3   and   3   2
 /                   \
4                     4
are identical.

    1             1
   / \           / \
  2   3   and   3   2
 /             /
4             4
are not identical.
*/

#include <iostream>
using namespace std;

/*
note: pointer of pointer for changing pointer copy which passed in function
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
     * @aaram a, b, the root of binary trees.
     * @return true if they are tweaked identical, or false.
     */
    bool isTweakedIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        if(a==NULL&&b==NULL)
            return true;
        else if(a==NULL||b==NULL)
            return false;
        
        if(a->val!=b->val)
            return false;
        else{
            return (isTweakedIdentical(a->left,b->left) && isTweakedIdentical(a->right,b->right) )
            || (isTweakedIdentical(a->right,b->left) && isTweakedIdentical(a->left,b->right));
        }
        
    }
};

int main(){

	return 0;
}