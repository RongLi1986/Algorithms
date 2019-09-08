/*
Minimum Subtree

Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

Example
Given a binary tree:

     1
   /   \
 -5     2
 / \   /  \
0   2 -4  -5 
return the node 1.
*/

/*
recursive + divide conque
*/

#include <iostream>
#include <vector>
#include <queue>
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
    int minSum = INT_MAX;
    TreeNode* minNode = NULL;
public:
    /**
     * @param root the root of binary tree
     * @return the root of the minimum subtree
     */
    TreeNode* findSubtree(TreeNode* root) {
        // Write your code here
        helper (root);
        
        return minNode;
    }
    
    int helper(TreeNode* root){
        if(root==NULL)
            return 0 ;
        int sum = root->val;
        if(root->left != NULL){
            int leftSubTree = helper(root->left);
            if(leftSubTree < minSum){
                minSum = leftSubTree;
                minNode = root->left;
            }
            sum += leftSubTree;
        }
        
        if(root->right!= NULL){
            int rightSubTree = helper(root->right);
            if(rightSubTree < minSum){
                minSum = rightSubTree;
                minNode = root->right;
            }
            sum += rightSubTree;
        }
        
        if(sum < minSum){
            minSum = sum;
            minNode = root;
        }
        
        return sum;
        
    }
};