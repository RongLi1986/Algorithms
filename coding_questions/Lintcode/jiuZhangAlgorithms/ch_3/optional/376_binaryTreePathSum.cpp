/*
Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.

A valid path is from root node to any of the leaf nodes.

Example
Given a binary tree, and target = 5:

     1
    / \
   2   4
  / \
 2   3
return

[
  [1, 2, 2],
  [1, 4]
]
*/


#include <iostream>
using namespace std;

/*
dfs + backtrace
divided and conque
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int> > res;
        vector<int> tmp;
        binaryTreePathSumHelper(root, target, res, tmp);
        
        return res;
    }
    
    void binaryTreePathSumHelper(TreeNode *root, int target,vector<vector<int> > &res, vector<int> tmp){
        
        if(root==NULL)
            return;
            
        target=target-root->val;
        tmp.push_back(root->val);
        
        if(target==0){
            if(!tmp.empty()){
                res.push_back(tmp);
                tmp.clear();
                return;
            }else{
                return;
            }
        }
        
        binaryTreePathSumHelper(root->left, target, res, tmp);
        binaryTreePathSumHelper(root->right, target, res, tmp);    
            
        return;
    }
    
};

int main(){

	return 0;
}