/*
Invert Binary Tree My Submissions Question Solution 
Total Accepted: 44844 Total Submissions: 111145 Difficulty: Easy
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
*/

/*
recursive swap node's left and right leap
*/

#include <iostream>
using namespace std;
/**
 *Definition for a binary tree node.
 */ 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		invertTreeRecursive(root);
		return root;
    }

	void invertTreeRecursive(TreeNode* root){
		if(root==NULL) return;
		
		TreeNode* tmp=root->left;
		root->left=root->right;
		root->right=tmp;

		invertTreeRecursive(root->left);
		invertTreeRecursive(root->right);

		return;
	}
};

int main(){

  Solution s;
  return 0;
}