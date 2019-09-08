/*
 Binary Tree Longest Consecutive Sequence

 Description
 Notes
 Testcase
 Judge
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child 
connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example
For example,

   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

/*

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxNum = 0;
public:
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return maxNum;
        
        dfsHelper(root,INT_MIN, 1);
        
        return maxNum;
    }
    
    //treenode , parent's val,  spath length
    void dfsHelper(TreeNode* root, int val, int num){
        if(root==0){
            maxNum = max(num, maxNum);
            return;
        }
        
        if(val == INT_MIN){ //root, no parent
            num = 1;
        }else{
            if(root->val - val ==1){
                num++;
            }else{
                maxNum = max(num,maxNum);
                num = 1;
            }
        }
        
        dfsHelper(root->left, root->val, num);
        dfsHelper(root->right, root->val, num);
        
        return;
    }
};