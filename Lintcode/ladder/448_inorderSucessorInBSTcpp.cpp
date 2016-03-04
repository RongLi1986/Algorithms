/*
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
dfs + O(n) scan
*/
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    vector<TreeNode*> res;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // write your code here
        res=inorderTraversal(root);
        
        for(int i=0;i<res.size();i++){
            if(res[i]==p){
                if(i==res.size()-1)
                    return NULL;
                return res[i+1];
            }
        }
        
        return NULL;
    }
    
    vector<TreeNode*> inorderTraversal(TreeNode *root) {
        // write your code here
        
        inorderTraversalRecursive(root);
        
        return res;
    }
    
    void inorderTraversalRecursive(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorderTraversalRecursive(root->left);
        res.push_back(root);
        inorderTraversalRecursive(root->right);
        
        return;
    }
};

int main(){

	return 0;
}