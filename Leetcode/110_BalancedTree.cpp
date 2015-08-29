/*
Balanced Binary Tree 
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
*/

/*
for each node, check left leap and right leap.
recursive to every node
*/


 /* Definition for binary tree*/
#include <iostream>
#include <cmath>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isBalanced(TreeNode *root) {
    	if(root==NULL) return true;

        int left=MaxDepth(root->left);
        int right=MaxDepth(root->right);
        if(abs(left-right)>1)
        	return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int MaxDepth(TreeNode *root) {
        if(root==NULL) return 0;

        return 1+max(MaxDepth(root->left),MaxDepth(root->right));
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
	a->right=d;

	Solution s;

	cout<<s.isBalanced(root)<<endl;
	
	return 0;
}