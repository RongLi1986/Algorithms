/*
Flatten Binary Tree to Linked List

Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.

Example
              1
               \
     1          2
    / \          \
   2   5    =>    3
  / \   \          \
 3   4   6          4
                     \
                      5
                       \
                        6
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

/*
inorder dfs 
*/
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root==nullptr)
            return;

        if(root->left!=nullptr&&root->right!=nullptr){
            
            TreeNode* leftNode=root->left;
            flatten(leftNode);
            TreeNode* rightNode=root->right;
            flatten(rightNode);
            root->left=nullptr;

            root->right=leftNode;

            TreeNode* ptr=leftNode;
            while(ptr->right!=nullptr)
                ptr=ptr->right;

            ptr->right=rightNode;

            

        }else if(root->left!=nullptr&&root->right==nullptr){
            TreeNode* leftNode=root->left;
            flatten(leftNode);
            root->left=nullptr;            
            root->right=leftNode;
            

        }else if(root->left==nullptr&&root->right!=nullptr){
            TreeNode* rightNode=root->right;
            flatten(rightNode);
        }else
            return;
    }
};