/*Minimum Depth of Binary Tree 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/*
sol:rescursive way
*/

/**
 Definition for binary tree
 */
#include <iostream>
 using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        
        //handle for single leap 
        if(root->left==NULL)
            return 1+minDepth(root->right);
        if(root->right==NULL)
            return 1+minDepth(root->left);
        
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};

int main(){
	TreeNode* root=new TreeNode(0);
	TreeNode* a=new TreeNode(0);
	TreeNode* b=new TreeNode(0);
	TreeNode* c=new TreeNode(0);
	TreeNode* d=new TreeNode(0);
	root->left=a;
	root->right=b;
	b->left=c;
	c->right=d;

	Solution s;
	cout<<s.minDepth(root)<<endl;

	return 0;
}