/*
Given a binary search tree and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.

Notice

You can assume there is no duplicate values in this tree + node.
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        TreeNode ** ptr=&root;
        insertNodeRecursive(ptr,node);
        
        return *ptr;
    }
    
    void insertNodeRecursive(TreeNode** root, TreeNode* node){
        if((*root) == NULL){
            *root = node;
            return;
        }else if((*root)->val>node->val){ //node go left
            if((*root)->left==NULL){
                (*root)->left=node;
                return;
            }else{
                insertNodeRecursive(&(*root)->left, node);
                return;
            }
        }else{ //go right
            if((*root)->right==NULL){
                (*root)->right=node;
                return;
            }else{
                insertNodeRecursive(&(*root)->right, node);
                return; 
            }
        }
    }
};

int main(){

	return 0;
}