/*
Validate Binary Search Tree 
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means?
*/

/*
sol:
in order traverse the Tree, and check whether it becomes from small to large.
*/


/**
 * Definition for binary tree
 */
 #include <iostream>
 #include <vector>
 using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
private:
	vector<int> v;
public:
    bool isValidBST(TreeNode *root) {
    	AddinVector(root);

    	int size=v.size();
    	int i=0;
    	for(;i<size-1;i++){
    		if(v[i]>v[i+1])
    			return false;
    	}

    	return true;
    }

    void AddinVector(TreeNode *root){
    	if(root==NULL) return;
    	AddinVector(root->left);
    	v.push_back(root->val);
    	AddinVector(root->right);
    }
};

int main(){
	

	return 0;
}