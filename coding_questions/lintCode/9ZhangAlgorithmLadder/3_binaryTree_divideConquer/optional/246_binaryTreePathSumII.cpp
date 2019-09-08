/*
Binary Tree Path Sum II

 Description
 Notes
 Testcase
 Judge
Your are given a binary tree in which each node contains a value. Design an algorithm to get all paths which sum to a given value. The path does not need to start or end at the root or a leaf, but it must go in a straight line down.

Have you met this question in a real interview? Yes
Example
Given a binary tree:

    1
   / \
  2   3
 /   /
4   2
for target = 6, return

[
  [2, 4],
  [1, 3, 2]
]
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
private:
    vector<vector<int>> ans;
public:
    /**
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode *root, int target) {
        // Write your code here
        binaryTreePaths(root, target);
        return ans;
    }
    
    void binaryTreePaths(TreeNode* root, int target) {
        // Write your code here
        if(root==NULL) return;
        
        vector<int> tmp;
        
        binaryTreePaths(root->left, target);
        binaryTreePathsHelper(root, tmp, 0, target);
        binaryTreePaths(root->right, target);
        
        return;
    }
    
    void binaryTreePathsHelper(TreeNode* root, vector<int> path, int sum, int target){
        
        //cout<<root->val<<endl;
        
        //if(path.empty()){ //first node
        path.push_back(root->val);
        
        sum += root->val;
        //end of path
        if(sum == target){
            //cout<<path<<endl;
            ans.push_back(path);
        }
        //cout<<path<<endl;
        
        if(root->left!=NULL){
            binaryTreePathsHelper(root->left, path, sum, target);
            
        }
        
        if(root->right!=NULL){
            binaryTreePathsHelper(root->right, path, sum, target);
        }
        
        
        return;
    }
};